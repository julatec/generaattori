#ifndef GENERAATORI_COMPILATION_UNIT_H
#define GENERAATORI_COMPILATION_UNIT_H

#include <iomanip>
#include <cstddef>
#include <iostream>
#include <new>
#include <typeinfo>
#include <type_traits>
#include <functional>
#include "tokens.h"

typedef decltype(::std::setw(0)) setw_t;
typedef decltype(::std::setfill('0')) setfill_t;

namespace generaattori {
inline namespace cpp {

#ifndef _GENERAATORI_INLINE_VISIBILITY
#define _GENERAATORI_INLINE_VISIBILITY \
__attribute__((__visibility__("hidden"), __always_inline__))
#endif

typedef enum {
  local_variable,
  public_variable,
  protected_variable,
  private_variable,
  namespace_name,
  type_name
} cpp_identifier_category_t;

template<cpp_identifier_category_t _Kind>
class identifier {

public:

  inline _GENERAATORI_INLINE_VISIBILITY
  constexpr identifier(const char *word, ::std::size_t size) :
      word_(word), size_(size) { }

  inline _GENERAATORI_INLINE_VISIBILITY
  constexpr identifier(const char *word) :
      word_(word), size_(-1) { }

  inline _GENERAATORI_INLINE_VISIBILITY
  constexpr identifier(const ::std::string &word) :
      identifier::identifier(word.c_str()) { }

  template<cpp_identifier_category_t _Kind1>
  inline _GENERAATORI_INLINE_VISIBILITY
  constexpr identifier(const identifier<_Kind1> &other) :
      identifier::identifier(other.word_, other.size_) { }

protected:

  const char *const word_;
  const ::std::size_t size_;

  template<typename _CharT, typename _Traits> friend
  class cu;

  template<cpp_identifier_category_t _Kind1> friend
  class identifier;

};

typedef identifier<namespace_name> vnamespace;
typedef identifier<type_name> vtype;
typedef identifier<local_variable> vlocal;
typedef identifier<private_variable> vprivate;
typedef identifier<protected_variable> vprotected;
typedef identifier<public_variable> vpublic;

struct custom_identifier_format {
  const char *prefix;
  const char fill;
  ::std::size_t width;
  const char *suffix;
};

template<typename T, const custom_identifier_format &_Format>
class custom_identifier {

public:

  static constexpr custom_identifier_format format = _Format;

  inline _GENERAATORI_INLINE_VISIBILITY
  constexpr custom_identifier(const T &word) :
      value_(word) { }

protected:

  const T value_;

  template<typename _CharT, typename _Traits> friend
  class cu;

};


class type_info {

public:

  type_info(const char *name, const ::std::type_info &) : name_(name) { }

  const char *name() const {
    return name_;
  }

private:

  const char *const name_;

};

constexpr unsigned int constexpr_hash(const char *str, int h = 0) {
  return !str[h] ? 5381 : (constexpr_hash(str, h + 1) * 33) ^ str[h];
}

class lineinfo {
public:

  constexpr lineinfo(const char *file, const ::std::size_t line) :
      file_(file), line_(line) { }

private:
  const char *const file_;
  const ::std::size_t line_;

  template<typename _CharT, typename _Traits> friend
  class cu;

};

template<char _Open, char _Close, typename _CharT2, typename _Traits2>
class basic_brackets;

template<typename _CharT, typename _Traits>
class basic_ident;

template<typename _CharT, typename _Traits>
class basic_block;

template<typename _CharT, typename _Traits=::std::char_traits<_CharT> >
class cu {

public:

  typedef _CharT char_type;
  typedef _Traits traits_type;

  typedef basic_brackets<'<', '>', _CharT, _Traits> abrackets_type;
  typedef basic_brackets<'(', ')', _CharT, _Traits> rbrackets_type;
  typedef basic_brackets<'{', '}', _CharT, _Traits> cbrackets_type;
  typedef basic_brackets<'[', ']', _CharT, _Traits> sbrackets_type;
  typedef basic_ident<_CharT, _Traits> ident_type;
  typedef basic_block<_CharT, _Traits> block_type;

public:

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

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(bool __n) {
    if (__n) {
      out_ << 't' << 'r' << 'u' << 'e';
    } else {
      out_ << 'f' << 'a' << 'l' << 's' << 'e';
    }
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(short __n) {
    verify_scape(identifier_);
    out_ << __n;
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(unsigned short __n) {
    verify_scape(identifier_);
    out_ << __n << 'U';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(int __n) {
    verify_scape(identifier_);
    out_ << __n;
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(unsigned int __n) {
    verify_scape(identifier_);
    out_ << __n << 'U';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(long __n) {
    verify_scape(identifier_);
    out_ << __n << "L";
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(unsigned long __n) {
    verify_scape(identifier_);
    out_ << __n << 'U' << 'L';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(long long __n) {
    verify_scape(identifier_);
    out_ << __n << 'L' << 'L';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(unsigned long long __n) {
    verify_scape(identifier_);
    out_ << __n << 'U' << 'L' << 'L';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(float __f) {
    verify_scape(identifier_);
    out_ << __f;
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(double __f) {
    verify_scape(identifier_);
    out_ << __f << 'D';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(long double __f) {
    verify_scape(identifier_);
    out_ << __f << "L";
    return *this;
  }

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
      out_ << 'n' << 'u' << 'l' << 'l' << 'p' << 't' << 'r';
    }
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const cpp_token_t &token_) {
    switch (token_) {
      case IFDEF_:
      case IFNDEF_:
      case DEFINE_:
      case IF_:
      case ENDIF_:
      case INCLUDE_:
      case LINE_:
        if (kind_ != nl_) {
          endl();
        }
        kind_ = token_;
        break;
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

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const vlocal &token_) {
    verify_scape(identifier_);
    scape_identifier(token_.word_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const vpublic &token_) {
    verify_scape(identifier_);
    scape_identifier(token_.word_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const vprivate &token_) {
    verify_scape(identifier_);
    out_ << '_';
    scape_identifier(token_.word_);
    out_ << '_' << '_';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const vprotected &token_) {
    verify_scape(identifier_);
    scape_identifier(token_.word_);
    out_ << '_';
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const vtype &token_) {
    verify_scape(identifier_);
    out_ << token_.word_;
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const vnamespace &token_) {
    verify_scape(identifier_);
    scape_identifier(token_.word_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &endl() {
    out_ << ::std::endl;
    for (int i = 0; i < level_; i++) {
      out_ << ' ' << ' ';
    }
    kind_ = nl_;
    return *this;
  }

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

public:

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(::std::ios_base &(*__pf)(::std::ios_base &)) {
    __pf(out_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const setw_t &iom_t6) {
    out_ << iom_t6;
    verify_scape(blank_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const setfill_t &iom_t4) {
    out_ << iom_t4;
    verify_scape(blank_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(::std::basic_ostream<_CharT, _Traits> &(*__pf)(
      ::std::basic_ostream<_CharT, _Traits> &)) {
    __pf(out_);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const ::std::type_info &info) {
    verify_scape(identifier_);
    for (const char *c = info.name(); *c; c++) {
      out_ << *c;
    }
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(const type_info &info) {
    verify_scape(identifier_);
    for (const char *c = info.name(); *c; c++) {
      out_ << *c;
    }
    return *this;
  }

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

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(::std::function<void(ident_type &)> __pf) {
    ident_type tab(*this);
    endl();
    __pf(tab);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(::std::function<void(block_type &)> __pf) {
    verify_scape(identifier_);
    block_type tab(*this);
    __pf(tab);
    return *this;
  }

  inline _GENERAATORI_INLINE_VISIBILITY
  cu &operator<<(::std::function<void()> __pf) {
    __pf();
    *this << sm_;
    return *this;
  }

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

  // Constructors
public:

  cu(::std::basic_ostream<_CharT, _Traits> &out) :
      out_(out),
      kind_(nl_),
      level_(0) {
  }

  ~cu() {
  }


protected:

  inline _GENERAATORI_INLINE_VISIBILITY
  void scape_identifier(const char *word_) {
    for (const char *c = word_; *c; c++) {
      switch (*c) {
        case '-':
        case ' ':
          out_ << '_';
          break;
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

  ::std::basic_ostream<_CharT, _Traits> &out_;
  cpp_token_t kind_;
  ::std::size_t level_;

  template<typename _CharT2, typename _Traits2> friend
  class basic_ident;

  template<typename _CharT2, typename _Traits2> friend
  class basic_block;

  template<char _Open, char _Close, typename _CharT2, typename _Traits2> friend
  class basic_brackets;

};

typedef cu<char> compilation_unit;
typedef cu<wchar_t> wcompilation_unit;

template<typename _CharT, typename _Traits=::std::char_traits<_CharT> >
class basic_ident {

public:

  inline _GENERAATORI_INLINE_VISIBILITY
  explicit basic_ident(cu<_CharT, _Traits> &cu) :
      cu_(cu),
      args_(0) {
    cu_.level_++;
  }

public:
  virtual ~basic_ident() { cu_.level_--; }

  cu<_CharT, _Traits> &operator++() {
    if (args_++) {
      cu_ << s_;
      cu_.endl();
    }
    return cu_;
  }

  cu<_CharT, _Traits> &operator++(int) {
    if (args_++) {
      cu_ << s_;
    }
    return cu_;
  }

protected:

  cu<_CharT, _Traits> &cu_;

private:

  basic_ident() = delete;

  basic_ident(const basic_ident &) = delete;

  basic_ident &operator=(const basic_ident &) = delete;

  ::std::size_t args_;

};


template<typename _CharT, typename _Traits=::std::char_traits<_CharT> >
class basic_block {

public:

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

public:

  virtual ~basic_block() {
    cu_.level_--;
    cu_.endl();
    cu_.out_ << '}';
  }

protected:

  cu<_CharT, _Traits> &cu_;

private:

  basic_block() = delete;

  basic_block(const basic_block &) = delete;

  basic_block &operator=(const basic_block &) = delete;

};

template<char _Open, char _Close, typename _CharT, typename _Traits=::std::char_traits<_CharT> >
class basic_brackets {

public:

  inline _GENERAATORI_INLINE_VISIBILITY
  explicit basic_brackets(cu<_CharT, _Traits> &cu) :
      cu_(cu),
      args_(0),
      nl_(false) {
    cu_.out_ << _Open;
  }

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

public:

  virtual ~basic_brackets() {
    if (nl_) {
      cu_.level_--;
      cu_.endl();
    }
    cu_.out_ << _Close;
  }

  cu<_CharT, _Traits> &operator++() {
    if (args_++) {
      cu_ << s_;
      cu_.endl();
    }
    return cu_;
  }

  cu<_CharT, _Traits> &operator++(int) {
    if (args_++) {
      cu_ << s_;
    }
    return cu_;
  }

protected:

  cu<_CharT, _Traits> &cu_;

private:

  basic_brackets() = delete;

  basic_brackets(const basic_brackets &) = delete;

  basic_brackets &operator=(const basic_brackets &) = delete;

  ::std::size_t args_;

  const bool nl_;

};

#define LineInfo ::generaattori::cpp::lineinfo(__FILE__, __LINE__)

#define TypeOf(type) ::generaattori::cpp::type_info(#type, typeid(type))

#define TypeHash(type) constexpr_hash(#type)

#define SetupCU(out) \
::generaattori::cpp::cu<decltype(out)::char_type, decltype(out)::traits_type> O(out)

#define Stmt(stmt) \
O << LineInfo << [&]() { O << stmt; }

#define Ident \
O << [&](decltype(O)::ident_type&args)

#define Initialize \
cl_ << [&](decltype(O)::ident_type&args)

#define ArgNL \
(++args)

#define ArgN \
(args++)

#define Members \
O << LineInfo

#define Block \
O << [&](decltype(O)::block_type&stmts)

#define ABrks \
[&](decltype(O)::abrackets_type&args)

#define CBrks \
[&](decltype(O)::cbrackets_type&args)

#define Body \
[&](decltype(O)::cbrackets_type&args, bool)

#define SBrks \
[&](decltype(O)::sbrackets_type&args)

#define RBrks \
[&](decltype(O)::rbrackets_type&args)

#define par0 \
[&](decltype(O)::rbrackets_type&args) { }

#define par1(first) \
[&](decltype(O)::rbrackets_type&args) { O << first; }

#define par2(first, second) \
[&](decltype(O)::rbrackets_type&args) { O << first << s << second; }

#define bpar1(first) \
[&](decltype(O)::sbrackets_type&args) { O << first; }

#define Parms \
[&](decltype(O)::rbrackets_type&args)

#define EParms \
[&](decltype(O)::rbrackets_type&args) { }

#define Public \
O << LineInfo << public_ << Initialize

#define Private \
O << LineInfo << public_ << Initialize

#define Protected \
O << LineInfo << public_ << Initialize

#define Member \
O << ::std::endl << LineInfo

#define IncludeLibrary(library) \
O << ::generaattori::INCLUDE_ << ABrks { O << ::generaattori::cpp::vlocal(library); }

#define IncludePath(library) \
O << ::generaattori::INCLUDE_ << library

#define If(cond) \
O << LineInfo \
<< ::generaattori::cpp::cpp_token_t::if_ \
<< [&](decltype(O)::rbrackets_type&args) { O << cond; } \
<< [&](decltype(O)::cbrackets_type&elements)

}
}

#endif //GENERAATORI_COMPILATION_UNIT_H
