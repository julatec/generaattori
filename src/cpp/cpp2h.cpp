/**
 * cpp2h
 * This executable converts a tsv file in a c++ header with:
 * - Enumeration.
 * - Categorization.
 * - Printing fucntion.
 * The input file shall contain the following header:
 * - Name of the reseverd word, it will be used as the enumeration field.
 * - Token, string literal corresponding to the reserved word.
 * - Category, one of word, puntuaction and blank.
 */
#include <list>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <boost/filesystem.hpp>
#include <generaattori/cpp/cu.h>

namespace fs = boost::filesystem;
using namespace generaattori;
using namespace generaattori::cpp;

const vtype cpp_token = "cpp_token_t";
const vtype cpp_token_categories = "cpp_token_categories_t";

typedef enum {
    column_name,
    column_token,
    column_category
} columns_t;

static const struct member_info {
    vpublic name;
    ::std::string column;
} members[] = {
        {"name",     "name",},
        {"token",    "token"},
        {"category", "category"},
};

constexpr custom_identifier_format reserved_word_format = {"", ' ', 30, "_"};
typedef custom_identifier<::std::string, reserved_word_format> reserved_word_t;

int main(int argc, char **argv) {

    if (argc < 3) {
        ::std::cerr
                << "USAGE: %s {sym} {rsrc}\n\n"
                << "  Creates {sym}.h from the contents of {rsrc}\n"
                << argv[0]
                << ::std::endl;
        return EXIT_FAILURE;
    }

    fs::path dst(argv[1]);
    fs::path src(argv[2]);

    ::std::string sym = src.filename().string();
    replace(sym.begin(), sym.end(), '.', '_');
    replace(sym.begin(), sym.end(), '-', '_');

    ::std::list<::std::map<::std::string, ::std::string>> entries;
    {
        ::std::fstream ifs(src.c_str(), ::std::fstream::in);
        ::std::vector<::std::string> header;

        std::string line;
        for (int line_number = 0; ::std::getline(ifs, line); line_number++) {

            std::istringstream iss(line);
            std::stringstream ss;

            char c;
            int column = 0;
            ::std::map<::std::string, ::std::string> entry;
            while ((c = iss.get()) && iss) {
                if (c == '\"') {
                    continue;
                } else if (c == '\t') {
                    if (line_number) {
                        entry[header[column]] = ss.str();
                    } else {
                        header.push_back(ss.str());
                    }
                    ss.str(std::string());
                    column++;
                } else {
                    ss << c;
                }
            }
            if (line_number) {
                entry[header[column]] = ss.str();
            } else {
                header.push_back(ss.str());
            }
            if (!entry.empty()) {
                entries.push_back(entry);
            }
        }
    }

    {
        create_directories(dst.parent_path());
        ::std::fstream out(dst.c_str(), ::std::fstream::out);
        const vlocal guard = "GENERAATORI_TOKENS_H";
        const vlocal clang = "clang";
        const vlocal diagnostic = "diagnostic";
        const vlocal push = "push";
        const vlocal pop = "pop";
        const vlocal ignored = "ignored";
        SetupCU(out);
        Members << IFNDEF_ << guard;
        Members << DEFINE_ << guard;
        Members << PRAGMA_ << clang << diagnostic << push;
        Members << PRAGMA_ << clang << diagnostic << ignored << "-Wunknown-pragmas";
        Members << PRAGMA_ << clang << diagnostic << ignored << "bugprone-reserved-identifier";
        Members << PRAGMA_ << clang << diagnostic << ignored << "OCUnusedGlobalDeclarationInspection";
        for (const char *library: {
                "iomanip",
                "cstddef",
                "iostream",
                "new",
                "typeinfo",
                "functional"
        }) {
            IncludeLibrary(library);
        }
        Members << namespace_ << "generaattori"_namespace << Body {
            Members << inline_ << namespace_ << "cpp"_namespace << Body {
                ::std::set<::std::string> categories;
                Members << typedef_ << enum_ << CBrks {
                    Ident {
                        int number = 0;
                        for (::std::map<::std::string, ::std::string> &entry: entries) {
                            categories.insert(entry[members[column_category].column]);
                            ArgNL << reserved_word_t(entry[members[column_name].column])
                                  //<< ::std::setw(30 - (int) entry[members[column_name].column].size())
                                  << set_ << ::std::setw(4) << number;
                            number++;
                        }
                        O.endl();
                    };
                } << cpp_token << sm_;

                Members << typedef_ << enum_ << CBrks {
                    Ident {
                        int number = 0;
                        for (const ::std::string &category : categories) {
                            ArgNL << vlocal(category) << ::std::setw(30 - (int) category.size())
                                  << set_ << number;
                            number++;
                        }
                        O.endl();
                    };
                } << cpp_token_categories << sm_;

                const vlocal vos = "os";
                const vlocal vt = "t";
                const vlocal _CharT = "_CharT";
                const vlocal _TraitsT = "_TraitsT";
                const vpublic category_of = "category_of";
                const vtype basic_ostream = "::std::basic_ostream<_CharT, _TraitsT>";
                Members << template_ << ABrks {
                    ArgNL << typename_ << _CharT;
                    ArgNL << typename_ << _TraitsT;
                } << basic_ostream << addressof_ << operator_ << lshift_ << Parms {
                    ArgNL << basic_ostream << addressof_ << vos;
                    ArgNL << const_ << cpp_token << addressof_ << vt;
                } << Body {
                    Members << switch_ << par1(vt) << Body {
                        for (::std::map<::std::string, ::std::string> &entry: entries) {
                            if (entry[members[column_token].column].empty()) {
                                continue;
                            }
                            Members << case_
                                    << reserved_word_t(entry[members[column_name].column])
                                    << Initialize {
                                        O << return_ << vos;
                                        for (const char c: entry[members[column_token].column]) {
                                            O << lshift_ << c;
                                        }
                                        O << sm_;
                                    };
                        }
                        Members << default_ << Initialize {
                            Stmt(break_);
                        };
                    };
                    Stmt(return_ << vos);
                };
                Members << constexpr_ << const_ << cpp_token_categories
                        << category_of << bpar1(entries.size()) << set_
                        << CBrks {
                            Members;
                            for (::std::map<::std::string, ::std::string> &entry: entries) {
                                ArgNL << vlocal(entry[members[column_category].column]);
                            }
                        } << sm_;
            };
        };
        Members << PRAGMA_ << clang << diagnostic << pop;
        Members << ENDIF_;
    }
    return EXIT_SUCCESS;
}