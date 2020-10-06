#ifndef GENERAATORI_COMPILATION_UNIT_H
#define GENERAATORI_COMPILATION_UNIT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "google-explicit-constructor"
#pragma ide diagnostic ignored "cert-dcl21-cpp"
#pragma ide diagnostic ignored "bugprone-reserved-identifier"

#include <iomanip>
#include <cstddef>
#include <iostream>
#include <new>
#include <typeinfo>
#include <type_traits>
#include <functional>
#include "tokens.h"

namespace generaattori {
    inline namespace cpp {

#ifndef _GENERAATORI_INLINE_VISIBILITY
#define _GENERAATORI_INLINE_VISIBILITY \
__attribute__((__visibility__("hidden"), __always_inline__))
#endif

        /**
         * Type of the operation ::std::setw, since it varies between platforms.
         */
        typedef decltype(::std::setw(0)) setw_t;

        /**
         * Type of the operation ::std::setfill, since it varies between platforms.
         */
        typedef decltype(::std::setfill('0')) setfill_t;

        /**
         * The types of identifier used in C++.
         */
        typedef enum {
            /**
             * Name of local variables, no addtional formatting applied.
             */
            local_variable,
            /**
             * Name of public fields, no addtional formatting applied.
             */
            public_variable,
            /**
             * Name of public fields, and underscore is added at the beggining.
             */
            protected_variable,
            /**
             * Name of public fields, and underscore is added at the beggining, and two at the end.
             */
            private_variable,
            /**
             * Name of public fields, no addtional formatting applied.
             */
            namespace_name,
            /**
             * Name of types.
             */
            type_name
        } cpp_identifier_category_t;

        /**
         * Wrapper class for any kind of identifier.
         * @tparam _Kind type of the identifer.
         */
        template<cpp_identifier_category_t _Kind>
        class identifier {

        public:

            /**
             * Constructor, with constant string and size.
             * @param word constant string reference
             * @param size size of the string refernce
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            constexpr identifier(const char *word, ::std::size_t size) :
                    word_(word), size_(size) {}

            /**
             * * Constructor, with constant string, but not known size.
             * @param * @param word constant string reference
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            constexpr identifier(const char *word) :
                    word_(word), size_(-1) {}

            /**
             * Constructor, with constant string referernce.
             * @param word constant string reference
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            constexpr identifier(const ::std::string &word) :
                    word_(word.c_str()), size_(word.size()) {}

            /**
             * Copy constructor.
             * @tparam _Kind1 type of the original identifier.
             *
             * @param other origional constant refererence.
             */
            template<cpp_identifier_category_t _Kind1>
            inline _GENERAATORI_INLINE_VISIBILITY
            constexpr explicit identifier(const identifier<_Kind1> &other) :
                    word_(other.word_), size_(other.size_) {}

        protected:

            /**
             * Constant reference.
             */
            const char *const word_{};

            /**
             * Length of the string.
             */
            const ::std::size_t size_{};

            template<typename _CharT, typename _Traits> friend
            class cu;

            template<cpp_identifier_category_t _Kind1> friend
            class identifier;

        };

        /**
         * Namespace identifier.
         */
        typedef identifier<namespace_name> vnamespace;

        /**
         * Literal operator for namespace identifier.
         * @param word string constant reference.
         * @param size string constant length.
         * @return constant namespace identifer.
         */
        inline vnamespace operator ""_namespace(const char *word, ::std::size_t size) {
            return {word, size};
        }

        /**
         * Type identifier.
         */
        typedef identifier<type_name> vtype;

        /**
         * Local variable identifier.
         */
        typedef identifier<local_variable> vlocal;

        /**
         * Literal operator for namespace identifier.
         * @param word string constant reference.
         * @param size string constant length.
         * @return constant local variable identifier.
         */
        inline vlocal operator ""_variable(const char *word, ::std::size_t size) {
            return {word, size};
        }

        /**
         * Private varible identifier.
         */
        typedef identifier<private_variable> vprivate;

        /**
         * Proctected variable identifier.
         */
        typedef identifier<protected_variable> vprotected;

        /**
         * Public variable identifier.
         */
        typedef identifier<public_variable> vpublic;

        /**
         * Format for custom idenfiers. The general format is:
         * <prefix><fill>*<id><suffix>.
         */
        struct custom_identifier_format {
            /**
             * Prefix.
             */
            const char *prefix;

            /**
             * Character used to fill.
             */
            const char fill;

            /**
             * Width of the identifer and the fill section.
             */
            ::std::size_t width;

            /**
             * Suffix.
             */
            const char *suffix;
        };

        /**
         * Custom identifier.
         * @tparam T identifier class.
         * @tparam _Format custom format.
         */
        template<typename T, const custom_identifier_format &_Format>
        class custom_identifier {

        public:

            /**
             * Custom idenfitier format.
             */
            static constexpr custom_identifier_format format = _Format;

            /**
             * Constructor.
             * @param word initialization using constant value.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            constexpr custom_identifier(const T &word) : value_(word) {}

        protected:

            /**
             * Value reference.
             */
            const T value_;

            template<typename _CharT, typename _Traits> friend
            class cu;

        };

        /**
         * Type information.
         */
        class type_info {

        public:

            /**
             * Constructor using constant string representation.
             * @param name
             */
            type_info(const char *name, const ::std::type_info &) : name_(name) {}

            /**
             * Getter ot the type name.
             * @return type name.
             */
            const char *name() const {
                return name_;
            }

        private:

            /**
             * Type name.
             */
            const char *const name_;

        };

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

        constexpr unsigned int constexpr_hash(const char *str, int h = 0) {
            return !str[h] ? 5381 : (constexpr_hash(str, h + 1) * 33) ^ str[h];
        }

#pragma clang diagnostic pop

        /**
         * Line information, defined by the line number and the filename.
         */
        class lineinfo {
        public:

            /**
             * Constructor using reqiured fields.
             * @param file filename as constant string.
             * @param line line number.
             */
            constexpr lineinfo(const char *file, const ::std::size_t line) :
                    file_(file), line_(line) {}

        private:

            /**
             * File name as string.
             */
            const char *const file_;

            /**
             * Line number.
             */
            const ::std::size_t line_;

            template<typename _CharT, typename _Traits> friend
            class cu;

        };

        /**
         * Braces type forwarding definition.
         * @tparam _Open Open Character.
         * @tparam _Close Close Character.
         * @tparam _CharT2 Charset.
         * @tparam _Traits2 Charset traits.
         */
        template<char _Open, char _Close, typename _CharT2, typename _Traits2>
        class basic_brackets;

        /**
         * Identation forward definition.
         * @tparam _CharT Charset.
         * @tparam _Traits Charset traits.
         */
        template<typename _CharT, typename _Traits>
        class basic_ident;

        /**
         * Block forward definition.
         * @tparam _CharT Charset.
         * @tparam _Traits Charset traits.
         */
        template<typename _CharT, typename _Traits>
        class basic_block;

        /**
         * Compilation Unit.
         * @tparam _CharT Charset.
         * @tparam _Traits Charset traits.
         */
        template<typename _CharT, typename _Traits=::std::char_traits<_CharT> >
        class cu {

        public:

            /**
             * Charset type.
             */
            typedef _CharT char_type;

            /**
             * Charset traits type.
             */
            typedef _Traits traits_type;

            /**
             * Angle brackets type.
             */
            typedef basic_brackets<'<', '>', _CharT, _Traits> abrackets_type;

            /**
             * Round brackets type.
             */
            typedef basic_brackets<'(', ')', _CharT, _Traits> rbrackets_type;

            /**
             * Curly brackts type.
             */
            typedef basic_brackets<'{', '}', _CharT, _Traits> cbrackets_type;

            /**
             * Square brakets type.
             */
            typedef basic_brackets<'[', ']', _CharT, _Traits> sbrackets_type;

            /**
             * Identation type.
             */
            typedef basic_ident<_CharT, _Traits> ident_type;

            /**
             * Block type.
             */
            typedef basic_block<_CharT, _Traits> block_type;

            /**
             * Prints a character literal.
             * @param __n input character.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(char __n) {
                verify_scape(identifier_);
                out_ << '\'';
                switch (__n) {
                    case '\n':
                        out_ << '\\' << 'n';
                    case '\t':
                        out_ << '\\' << 't';
                    case '\r':
                        out_ << '\\' << 'r';
                    default:
                        out_ << __n;
                        break;
                }
                out_ << '\'';
                return *this;
            }

            /**
             * Prints a boolean literal.
             * @param __n input boolean.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(bool __n) {
                if (__n) {
                    out_ << 't' << 'r' << 'u' << 'e';
                } else {
                    out_ << 'f' << 'a' << 'l' << 's' << 'e';
                }
                return *this;
            }

            /**
             * Prints a short literal.
             * @param __n input short.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(short __n) {
                verify_scape(identifier_);
                out_ << __n;
                return *this;
            }

            /**
             * Prints an unsingned long literal.
             * @param __n input unsigned long.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(unsigned short __n) {
                verify_scape(identifier_);
                out_ << __n << 'U';
                return *this;
            }

            /**
             * Prints an integer literal.
             * @param __n input integer.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(int __n) {
                verify_scape(identifier_);
                out_ << __n;
                return *this;
            }

            /**
             * Prints an unsigned integer literal.
             * @param __n input unsigned integer.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(unsigned int __n) {
                verify_scape(identifier_);
                out_ << __n << 'U';
                return *this;
            }

            /**
             * Prints a long literal.
             * @param __n input long.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(long __n) {
                verify_scape(identifier_);
                out_ << __n << "L";
                return *this;
            }

            /**
             * Prints an unsigned long literal.
             * @param __n input unsignend long literal.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(unsigned long __n) {
                verify_scape(identifier_);
                out_ << __n << 'U' << 'L';
                return *this;
            }

            /**
             * Prints a long long literal.
             * @param __n input long long literal.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(long long __n) {
                verify_scape(identifier_);
                out_ << __n << 'L' << 'L';
                return *this;
            }

            /**
             * Prints an unsigned long long literal.
             * @param __n input unsigned long long.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(unsigned long long __n) {
                verify_scape(identifier_);
                out_ << __n << 'U' << 'L' << 'L';
                return *this;
            }

            /**
             * Prints a float literal.
             * @param __f input float.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(float __f) {
                verify_scape(identifier_);
                out_ << __f << 'F';
                return *this;
            }

            /**
             * Prints a double literal.
             * @param __f input double.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(double __f) {
                verify_scape(identifier_);
                out_ << __f << 'D';
                return *this;
            }

            /**
             * Prints a long double literal.
             * @param __f input long double.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(long double __f) {
                verify_scape(identifier_);
                out_ << __f << "L";
                return *this;
            }

            /**
             * Prints a string literal.
             * @param __s input string.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const char *__s) {
                verify_scape(identifier_);
                if (__s) {
                    out_ << '"';
                    for (; *__s; __s++)
                        switch (*__s) {
                            case '\n':
                                out_ << '\\' << 'n';
                                break;
                            case '\t':
                                out_ << '\\' << 't';
                                break;
                            case '\r':
                                out_ << '\\' << 'r';
                                break;
                            case '\\':
                                out_ << '\\' << '\\';
                                break;
                            case '\'':
                                out_ << '\'';
                            case '"':
                                out_ << '\\' << '"';
                                break;
                            default:
                                out_ << *__s;
                                break;
                        }
                    out_ << '"';
                } else {
                    out_ << 'n' << 'u' << 'l' << 'l' << 'p' << 't' << 'r';
                }
                return *this;
            }

            /**
             * Prints a wide string literal.
             * @param __s input wide string.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const wchar_t *__s) {
                verify_scape(identifier_);
                if (__s) {
                    out_ << 'L' << '"';
                    for (; *__s; __s++)
                        switch (*__s) {
                            case '\n':
                                out_ << '\\' << 'n';
                                break;
                            case '\t':
                                out_ << '\\' << 't';
                                break;
                            case '\r':
                                out_ << '\\' << 'r';
                                break;
                            case '\\':
                                out_ << '\\' << '\\';
                                break;
                            case '\'':
                                out_ << '\'';
                            case '"':
                                out_ << '\\' << '"';
                                break;
                            default:
                                out_ << *__s;
                                break;
                        }
                    out_ << '"';
                } else {
                    out_ << 'n' << 'u' << 'l' << 'l' << 'p' << 't' << 'r';
                }
                return *this;
            }

            /**
             * Prints unicode string literal.
             * @param __s input unicode literal.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const char16_t *__s) {
                verify_scape(identifier_);
                if (__s) {
                    out_ << 'u' << '"';
                    for (; *__s; __s++)
                        switch (*__s) {
                            case '\n':
                                out_ << '\\' << 'n';
                                break;
                            case '\t':
                                out_ << '\\' << 't';
                                break;
                            case '\r':
                                out_ << '\\' << 'r';
                                break;
                            case '\\':
                                out_ << '\\' << '\\';
                                break;
                            case '\'':
                                out_ << '\'';
                            case '"':
                                out_ << '\\' << '"';
                                break;
                            default:
                                out_ << *__s;
                                break;
                        }
                    out_ << '"';
                } else {
                    out_ << 'n' << 'u' << 'l' << 'l' << 'p' << 't' << 'r';
                }
                return *this;
            }

            /**
             * Prints char32 string literal.
             * @param __s input char32 string.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const char32_t *__s) {
                verify_scape(identifier_);
                if (__s) {
                    out_ << 'U' << '"';
                    for (; *__s; __s++)
                        switch (*__s) {
                            case '\n':
                                out_ << '\\' << 'n';
                                break;
                            case '\t':
                                out_ << '\\' << 't';
                                break;
                            case '\r':
                                out_ << '\\' << 'r';
                                break;
                            case '\\':
                                out_ << '\\' << '\\';
                                break;
                            case '\'':
                                out_ << '\'';
                            case '"':
                                out_ << '\\' << '"';
                                break;
                            default:
                                out_ << *__s;
                                break;
                        }
                    out_ << '"';
                } else {
                    out_ << nullptr_;
                }
                return *this;
            }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"

            /**
             * Prints a reserved word.
             * @param token_ reseved word.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const cpp_token_t &token_) {
                switch (token_) {
                    /// The preprocessor directives requires a new line before them.
                    case IFDEF_:
                    case IFNDEF_:
                    case DEFINE_:
                    case IF_:
                    case ENDIF_:
                    case INCLUDE_:
                    case PRAGMA_:
                    case LINE_:
                        if (kind_ != nl_) {
                            endl();
                        }
                        kind_ = token_;
                        break;
                        /// In any other case, just verify the if it is required a space.
                    default:
                        verify_scape(token_);
                        break;
                }
                out_ << token_;
                switch (token_) {
                    case cl_:
                        kind_ = identifier_;
                        break;
                    default:
                        break;
                }
                return *this;
            }

#pragma clang diagnostic pop

            /**
             * Prints a local variable.
             * @param token_ local variable
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const vlocal &token_) {
                verify_scape(identifier_);
                scape_identifier(token_.word_);
                return *this;
            }

            /**
             * Prints a public variable.
             * @param token_ public variable.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const vpublic &token_) {
                verify_scape(identifier_);
                scape_identifier(token_.word_);
                return *this;
            }

            /**
             * Prints a private variable.
             * @param token_ private variable.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const vprivate &token_) {
                verify_scape(identifier_);
                out_ << '_';
                scape_identifier(token_.word_);
                out_ << '_' << '_';
                return *this;
            }

            /**
             * Prints a protected variable.
             * @param token_ protected variable.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const vprotected &token_) {
                verify_scape(identifier_);
                scape_identifier(token_.word_);
                out_ << '_';
                return *this;
            }

            /**
             * Prints a type name.
             * @param token_ type name.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const vtype &token_) {
                verify_scape(identifier_);
                out_ << token_.word_;
                return *this;
            }

            /**
             * Prints a namespace.
             * @param token_ namespace to print.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const vnamespace &token_) {
                verify_scape(identifier_);
                scape_identifier(token_.word_);
                return *this;
            }

            /**
             * Prints a new line.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &endl() {
                out_ << ::std::endl;
                for (int i = 0; i < level_; i++) {
                    out_ << ' ' << ' ';
                }
                kind_ = nl_;
                return *this;
            }

            /**
             * Prints a source file line information.
             * @param word_ line information.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const lineinfo &word_) {
                if (kind_ != nl_) {
                    endl();
                }
                *this << LINE_;
                out_ << ' ' << word_.line_;
                operator<<(word_.file_);
                endl();
                return *this;
            }

            /**
             * Executes the given printing function in the underlying output stream.
             * @param __pf function to exectuted
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::ios_base &(*__pf)(::std::ios_base &)) {
                __pf(out_);
                return *this;
            }

            /**
             * Configures the underlying output stream with the given setw config.
             * @param iom_t6 witdh formatting.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const setw_t &iom_t6) {
                out_ << iom_t6;
                verify_scape(blank_);
                return *this;
            }

            /**
             * Configures the underlying output stream with the fill character configuration.
             * @param iom_t4 fill character formatting.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const setfill_t &iom_t4) {
                out_ << iom_t4;
                verify_scape(blank_);
                return *this;
            }

            /**
             * Executes the given printing function on the underlying output stream.
             * @param __pf priting function to be executed.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::basic_ostream<_CharT, _Traits> &(*__pf)(
                    ::std::basic_ostream<_CharT, _Traits> &)) {
                __pf(out_);
                return *this;
            }

            /**
             * Prints a type info.
             * @param info type info to be printed.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const ::std::type_info &info) {
                verify_scape(identifier_);
                for (const char *c = info.name(); *c; c++) {
                    out_ << *c;
                }
                return *this;
            }

            /**
             * Prints a type info.
             * @param info type info to be printed.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const type_info &info) {
                verify_scape(identifier_);
                for (const char *c = info.name(); *c; c++) {
                    out_ << *c;
                }
                return *this;
            }

            /**
             * Open and closes an angle brackets block and execute the given printing function.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(abrackets_type &)> __pf) {
                verify_scape(void_);
                {
                    abrackets_type tab(*this);
                    verify_scape(blank_);
                    __pf(tab);
                    verify_scape(blank_);
                }
                kind_ = blank_;
                return *this;
            }

            /**
             * Open and closes an square brackets block and execute the given printing function.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(sbrackets_type &)> __pf) {
                verify_scape(void_);
                {
                    sbrackets_type tab(*this);
                    __pf(tab);
                }
                kind_ = void_;
                return *this;
            }

            /**
             * Open and closes an round brackets block and execute the given printing function.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(rbrackets_type &)> __pf) {
                verify_scape(blank_);
                {
                    rbrackets_type tab(*this);
                    __pf(tab);
                }
                kind_ = void_;
                return *this;
            }

            /**
             * Open and closes an curly brackets block and execute the given printing function.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(cbrackets_type &)> __pf) {
                verify_scape(void_);
                {
                    cbrackets_type tab(*this);
                    __pf(tab);
                }
                kind_ = void_;
                return *this;
            }

            /**
             * Open and closes an curly brackets block and execute the given printing function.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(cbrackets_type &, bool)> __pf) {
                verify_scape(void_);
                {
                    cbrackets_type tab(*this, true);
                    __pf(tab, true);
                }
                kind_ = void_;
                return *this;
            }

            /**
             * Open and closes an identation block and execute the given printing function inside
             * the block.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(ident_type &)> __pf) {
                ident_type tab(*this);
                endl();
                __pf(tab);
                return *this;
            }

            /**
             * Open and closes a block and executes the given funtion inside the block.
             * @param __pf function to be executed inside a block.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(::std::function<void(block_type &)> __pf) {
                verify_scape(identifier_);
                block_type tab(*this);
                __pf(tab);
                return *this;
            }

            /**
             * Executes the given printing function as a statement.
             * @param __pf function to be executed.
             * @return self reference.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            cu &operator<<(const ::std::function<void()> &__pf) {
                __pf();
                *this << sm_;
                return *this;
            }

            /**
             * Prints a custom identifier.
             * @tparam T Custom identifer type.
             * @tparam _Format format of the custom identifier.
             * @param formatted custom identifer.
             * @return self reference.
             */
            template<typename T, const custom_identifier_format &_Format>
            cu &operator<<(const custom_identifier<T, _Format> &formatted) {
                verify_scape(identifier_);
                for (const char *c = custom_identifier<T, _Format>::format.prefix;
                     c && *c; c++) {
                    out_ << *c;
                }
                if (custom_identifier<T, _Format>::format.width) {
                    out_ << ::std::setw(custom_identifier<T, _Format>::format.width);
                    out_ << ::std::setfill(custom_identifier<T, _Format>::format.fill);
                }
                out_ << formatted.value_;
                for (const char *c = custom_identifier<T, _Format>::format.suffix;
                     c && *c; c++) {
                    out_ << *c;
                }
                return *this;
            }

        public:

            /**
             * Constructor with output stream.
             * @param out underlying output stream.
             */
            cu(::std::basic_ostream<_CharT, _Traits> &out) :
                    out_(out),
                    kind_(nl_),
                    level_(0) {
            }

            /**
             * Default destructor.
             */
            ~cu() = default;

        protected:

            /**
             * Scape an identifer in case it contains spaces or dashes.
             * @param word_ identifer.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            void scape_identifier(const char *word_) {
                for (const char *c = word_; *c; c++) {
                    switch (*c) {
                        case '-':
                        case ' ':
                        case '_':
                            out_ << '_';
                            break;
                        default:
                            out_ << *c;
                            break;
                    }
                }
            }


        private:

            /**
             * Prints a space in case the last printed token is of the same kind of the new token
             * @param new_category kind of the new token.
             */
            void verify_scape(cpp_token_t new_category) {
                switch (category_of[kind_]) {
                    case blank:
                        break;
                    default:
                        if (category_of[kind_] == category_of[new_category]) {
                            out_ << ' ';
                        }
                        break;
                }
                kind_ = new_category;
            }

            /**
             * Undelying output stream.
             */
            ::std::basic_ostream<_CharT, _Traits> &out_;

            /**
             * Last token kind.
             */
            cpp_token_t kind_;

            /**
             * Identation Level.
             */
            ::std::size_t level_;

            template<typename _CharT2, typename _Traits2> friend
            class basic_ident;

            template<typename _CharT2, typename _Traits2> friend
            class basic_block;

            template<char _Open, char _Close, typename _CharT2, typename _Traits2> friend
            class basic_brackets;

        };

        /**
         * Compilation unit for char type and default char traits.
         */
        typedef cu<char> compilation_unit;

        /**
         * Compilation unit for wide char type and default char traits.
         */
        typedef cu<wchar_t> wcompilation_unit;

        /**
         * Identation block. Handles Indentation level.
         * @tparam _CharT Charset
         * @tparam _Traits Charset traits.
         */
        template<typename _CharT, typename _Traits=::std::char_traits<_CharT> >
        class basic_ident {

        public:

            /**
             * Constructor.
             * @param cu parent compilation unit.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            explicit basic_ident(cu<_CharT, _Traits> &cu) :
                    cu_(cu),
                    args_(0) {
                cu_.level_++;
            }

            /**
             * Default constructor removed.
             */
            basic_ident() = delete;

            /**
             * Copy constructor removed.
             */
            basic_ident(const basic_ident &) = delete;

            /**
             * Assingation operator removed.
             * @return
             */
            basic_ident &operator=(const basic_ident &) = delete;

            /**
             * Destructor, reduces identation level.
             */
            virtual ~basic_ident() { cu_.level_--; }

            /**
             * Add a comma separator and a new line.
             * @return parent compilation unit.
             */
            cu<_CharT, _Traits> &operator++() {
                if (args_++) {
                    cu_ << s_;
                    cu_.endl();
                }
                return cu_;
            }

            /**
             * Adds a comma separator, but not a new line.
             * @return parent compilation unit.
             */
            cu<_CharT, _Traits> &operator++(int) {
                if (args_++) {
                    cu_ << s_;
                }
                return cu_;
            }

        protected:

            /**
             * Parent compilation unit.
             */
            cu<_CharT, _Traits> &cu_;


        private:

            /**
             * Current arguments count.
             */
            ::std::size_t args_;

        };

        /**
         * Block, handles identation level and open and close markers.
         * @tparam _CharT Charset
         * @tparam _Traits Charset traits.
         */
        template<typename _CharT, typename _Traits=::std::char_traits<_CharT> >
        class basic_block {

        public:

            /**
             * Constructor. Increases idenation level and open braces.
             * @param cu parent compilation unit.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            explicit basic_block(cu<_CharT, _Traits> &cu) : cu_(cu) {
                switch (category_of[cu_.kind_]) {
                    case punctuation:
                        cu_.endl();
                        cu_.out_ << '{';
                        break;
                    default:
                        cu_.out_ << ' ' << '{';
                        break;
                }
                cu_.level_++;
            }

            /**
             * Desctructor, reduces idenation and close braces.
             */
            virtual ~basic_block() {
                cu_.level_--;
                cu_.endl();
                cu_.out_ << '}';
            }

            /**
             * Default constructor removed.
             */
            basic_block() = delete;

            /**
             * Copy constructor removed.
             */
            basic_block(const basic_block &) = delete;

            /**
             * Assignation constructor removed.
             * @return
             */
            basic_block &operator=(const basic_block &) = delete;

        protected:

            /**
             * Parent compilation unit.
             */
            cu<_CharT, _Traits> &cu_;

        };

        /**
         * Braces block, handles identaion and opening and closing markers.
         * @tparam _Open open marker
         * @tparam _Close close marker
         * @tparam _CharT Charset
         * @tparam _Traits Charset traits.
         */
        template<char _Open, char _Close, typename _CharT, typename _Traits=::std::char_traits<_CharT> >
        class basic_brackets {

        public:

            /**
             * Consturtor. Opens the marker.
             * @param cu parent compilation unit.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            explicit basic_brackets(cu<_CharT, _Traits> &cu) :
                    cu_(cu),
                    args_(0),
                    nl_(false) {
                cu_.out_ << _Open;
            }

            /**
             * Consturtor. Opens the marker, and adds a new line.
             * @param cu parent compilation unit.
             * @param nl whether add a new line and increase identation level.
             */
            inline _GENERAATORI_INLINE_VISIBILITY
            explicit basic_brackets(cu<_CharT, _Traits> &cu, bool nl)
                    :
                    cu_(cu),
                    args_(0),
                    nl_(nl) {
                cu_.out_ << _Open;
                if (nl_) {
                    cu_.level_++;
                    cu_.endl();
                }
            }

            /**
             * Destructor, closes the marker and reduces the identation level when it is needed.
             */
            virtual ~basic_brackets() {
                if (nl_) {
                    cu_.level_--;
                    cu_.endl();
                }
                cu_.out_ << _Close;
            }

            /**
             * Default construtor removed.
             */
            basic_brackets() = delete;

            /**
             * Copy construtor removed.
             */
            basic_brackets(const basic_brackets &) = delete;

            /**
             * Assignation operator removed.
             * @return nothing.
             */
            basic_brackets &operator=(const basic_brackets &) = delete;

            /**
             * Increses the number of arguments, adding a comma separator when it is needed, and a new line.
             * @return parent compilation unit.
             */
            cu<_CharT, _Traits> &operator++() {
                if (args_++) {
                    cu_ << s_;
                    cu_.endl();
                }
                return cu_;
            }

            /**
             * Increses the number of arguments, adding a comma separator when it is needed.
             * @return parent compilation unit.
             */
            cu<_CharT, _Traits> &operator++(int) {
                if (args_++) {
                    cu_ << s_;
                }
                return cu_;
            }

        protected:

            /**
             * Parent compilation unit.
             */
            cu<_CharT, _Traits> &cu_;

        private:

            /**
             * Current argument count.
             */
            ::std::size_t args_;

            /**
             * Whetever add a new line.
             */
            const bool nl_;

        };

/// Current line info constant expression.
#define LineInfo ::generaattori::cpp::lineinfo(__FILE__, __LINE__)

/// Type information constant expression, compilation safe.
#define TypeOf(type) ::generaattori::cpp::type_info(#type, typeid(type))

/// Hash code for type
#define TypeHash(type) constexpr_hash(#type)

/// Initializes a compilation unit with a given output stream.
#define SetupCU(out) \
::generaattori::cpp::cu<decltype(out)::char_type, decltype(out)::traits_type> O(out)

/// Prints a given statemenet with line information.
#define Stmt(stmt) \
O << LineInfo << [&]() { O << stmt; }

/// Opens a identation block.
#define Ident \
O << [&](decltype(O)::ident_type&args)

/// Opens a initialization block.
#define Initialize \
cl_ << [&](decltype(O)::ident_type&args)

/// Increases parameter number, new line first.
#define ArgNL \
(++args)

/// Increases parameter number, no new line added.
#define ArgN \
(args++)

///
#define Members \
O << LineInfo

/// Opens a block segment
#define Block \
O << [&](decltype(O)::block_type&stmts)

/// Opens a angle brackets block segment.
#define ABrks \
[&](decltype(O)::abrackets_type&args)

/// Opens a curly brackets blcok segment.
#define CBrks \
[&](decltype(O)::cbrackets_type&args)

/// Opens a code block segment.
#define Body \
[&](decltype(O)::cbrackets_type&args, bool)

/// Opens a square brackets block segment.
#define SBrks \
[&](decltype(O)::sbrackets_type&args)

/// Opens a round brackets block segment.
#define RBrks \
[&](decltype(O)::rbrackets_type&args)

/// Opens and closes a parameter block.
#define par0 \
[&](decltype(O)::rbrackets_type&args) { }

/// Opens and closes a parameter block for the given single parameter.
#define par1(first) \
[&](decltype(O)::rbrackets_type&args) { O << first; }

/// Opens and closes a parameter block for the given pair of parameters.
#define par2(first, second) \
[&](decltype(O)::rbrackets_type&args) { O << first << s << second; }

/// Opens and closes a square parameter block for the given single parameter.
#define bpar1(first) \
[&](decltype(O)::sbrackets_type&args) { O << first; }

/// Opens a paremeters block.
#define Parms \
[&](decltype(O)::rbrackets_type&args)

/// Open and closes a parameters block.
#define EParms \
[&](decltype(O)::rbrackets_type&args) { }

/// Opens a public members section
#define Public \
O << LineInfo << public_ << Initialize

/// Opens a private members section
#define Private \
O << LineInfo << private_ << Initialize

/// Opens a protected members section
#define Protected \
O << LineInfo << protected_ << Initialize

/// Opens a members section
#define Member \
O << ::std::endl << LineInfo

/// Prints a include library directive
#define IncludeLibrary(library) \
O << ::generaattori::INCLUDE_ << ABrks { O << ::generaattori::cpp::vlocal(library); }

/// Prints a include file directive
#define IncludePath(library) \
O << ::generaattori::INCLUDE_ << library

/// Prints an if statement with given condition and open the then block.
#define If(cond) \
O << LineInfo \
<< ::generaattori::cpp::cpp_token_t::if_ \
<< [&](decltype(O)::rbrackets_type&args) { O << cond; } \
<< [&](decltype(O)::cbrackets_type&elements)

    }
}

#pragma clang diagnostic pop
#endif //GENERAATORI_COMPILATION_UNIT_H

