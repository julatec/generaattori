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
    SetupCU(out);

    const vlocal guard = "GENERAATORI_TOKENS_H";
    O << IFNDEF_ << guard;
    O << DEFINE_ << guard;
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

    O << LineInfo << namespace_ << vnamespace("generaattori") << Body {
      O << LineInfo << inline_ << namespace_ << vnamespace("cpp") << Body {

        ::std::set<::std::string> categories;
        Members << typedef_ << enum_ << CBrks {
          Ident {
            int number = 0;
            for (::std::map<::std::string, ::std::string> &entry: entries) {
              categories.insert(entry[members[column_category].column]);
              ArgNL << vlocal(entry[members[column_name].column] + "_")
                    << ::std::setw(
                        30 - entry[members[column_name].column].size())
                    << set_ << number;
              number++;
            }
            O.endl();
          };
        } << cpp_token << sm_;

        Members << typedef_ << enum_ << CBrks {
          Ident {
            int number = 0;
            for (const ::std::string &category : categories) {
              ArgNL << vlocal(category) << ::std::setw(30 - category.size())
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
                      << vlocal(entry[members[column_name].column] + "_")
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
                  O << LineInfo;
                  for (::std::map<::std::string, ::std::string> &entry: entries) {
                    ArgNL << vlocal(entry[members[column_category].column]);
                  }
                } << sm_;
      };
    };
    O << ENDIF_;
  }
  return EXIT_SUCCESS;
}