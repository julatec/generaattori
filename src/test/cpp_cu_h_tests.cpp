#include <tms2/cpp/cu.h>
#include <tms2/gen/da_identifiers.h>
#include <gtest/gtest.h>

using namespace std;
using namespace tms2;

TEST(CompilationUnit, Literals) {

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << true;
    ASSERT_EQ("true", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << false;
    ASSERT_EQ("false", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << 7;
    ASSERT_EQ("7", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << 7L;
    ASSERT_EQ("7L", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << 7UL;
    ASSERT_EQ("7UL", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << 7ULL;
    ASSERT_EQ("7ULL", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << 7.1F;
    ASSERT_EQ("7.1F", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << 7.1L;
    ASSERT_EQ("7.1L", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << "simple text \t";
    ASSERT_EQ("\"simple text \\t\"", ss.str());
  }

  {
    wstringstream ss;
    wcompilation_unit cu(ss);
    cu << L"simple text \t";
    ASSERT_EQ(L"L\"simple text \\t\"", ss.str());
  }

}

TEST(CompilationUnit, ReservedWords) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << alignas_;
    ASSERT_EQ("alignas", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << alignof_;
    ASSERT_EQ("alignof", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << asm_;
    ASSERT_EQ("asm", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << auto_;
    ASSERT_EQ("auto", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << break_;
    ASSERT_EQ("break", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << case_;
    ASSERT_EQ("case", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << catch_;
    ASSERT_EQ("catch", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << class_;
    ASSERT_EQ("class", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << const_;
    ASSERT_EQ("const", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << constexpr_;
    ASSERT_EQ("constexpr", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << const_cast_;
    ASSERT_EQ("const_cast", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << continue_;
    ASSERT_EQ("continue", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << decltype_;
    ASSERT_EQ("decltype", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << default_;
    ASSERT_EQ("default", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << delete_;
    ASSERT_EQ("delete", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << do_;
    ASSERT_EQ("do", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << double_;
    ASSERT_EQ("double", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << dynamic_cast_;
    ASSERT_EQ("dynamic_cast", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << else_;
    ASSERT_EQ("else", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << enum_;
    ASSERT_EQ("enum", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << explicit_;
    ASSERT_EQ("explicit", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << export_;
    ASSERT_EQ("export", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << extern_;
    ASSERT_EQ("extern", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << for_;
    ASSERT_EQ("for", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << friend_;
    ASSERT_EQ("friend", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << goto_;
    ASSERT_EQ("goto", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << if_;
    ASSERT_EQ("if", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << inline_;
    ASSERT_EQ("inline", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << mutable_;
    ASSERT_EQ("mutable", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << namespace_;
    ASSERT_EQ("namespace", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << new_;
    ASSERT_EQ("new", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << noexcept_;
    ASSERT_EQ("noexcept", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << nullptr_;
    ASSERT_EQ("nullptr", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << operator_;
    ASSERT_EQ("operator", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << private_;
    ASSERT_EQ("private", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << protected_;
    ASSERT_EQ("protected", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << public_;
    ASSERT_EQ("public", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << register_;
    ASSERT_EQ("register", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << reinterpret_cast_;
    ASSERT_EQ("reinterpret_cast", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << return_;
    ASSERT_EQ("return", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << sizeof_;
    ASSERT_EQ("sizeof", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << static_;
    ASSERT_EQ("static", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << static_assert_;
    ASSERT_EQ("static_assert", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << static_cast_;
    ASSERT_EQ("static_cast", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << struct_;
    ASSERT_EQ("struct", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << switch_;
    ASSERT_EQ("switch", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << template_;
    ASSERT_EQ("template", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << this_;
    ASSERT_EQ("this", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << thread_local_;
    ASSERT_EQ("thread_local", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << throw_;
    ASSERT_EQ("throw", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << try_;
    ASSERT_EQ("try", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << typedef_;
    ASSERT_EQ("typedef", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << typeid_;
    ASSERT_EQ("typeid", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << typename_;
    ASSERT_EQ("typename", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << union_;
    ASSERT_EQ("union", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << unsigned_;
    ASSERT_EQ("unsigned", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << using_;
    ASSERT_EQ("using", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << virtual_;
    ASSERT_EQ("virtual", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << volatile_;
    ASSERT_EQ("volatile", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << while_;
    ASSERT_EQ("while", ss.str());
  }

}

TEST(CompilationUnit, Punctuations) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << sm_;
    ASSERT_EQ(";", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << cl_;
    ASSERT_EQ(":", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << s_;
    ASSERT_EQ(",", ss.str());
  }

}

TEST(CompilationUnit, Operators) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << set_;
    ASSERT_EQ("=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << sum_eq_;
    ASSERT_EQ("+=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << sub_eq_;
    ASSERT_EQ("-=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << mul_eq_;
    ASSERT_EQ("*=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << div_eq_;
    ASSERT_EQ("/=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << mod_eq_;
    ASSERT_EQ("%=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << or_eq_;
    ASSERT_EQ("|=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << and_eq_;
    ASSERT_EQ("&=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << xor_eq_;
    ASSERT_EQ("^=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << rshift_eq_;
    ASSERT_EQ(">>=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << lshift_eq_;
    ASSERT_EQ("<<=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << sum_;
    ASSERT_EQ("+", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << sub_;
    ASSERT_EQ("-", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << mul_;
    ASSERT_EQ("*", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << div_;
    ASSERT_EQ("/", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << mod_;
    ASSERT_EQ("%", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << bitor_;
    ASSERT_EQ("|", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << bitand_;
    ASSERT_EQ("&", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << rshift_;
    ASSERT_EQ(">>", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << lshift_;
    ASSERT_EQ("<<", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << compl_;
    ASSERT_EQ("~", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << not_;
    ASSERT_EQ("!", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << and_;
    ASSERT_EQ("&&", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << or_;
    ASSERT_EQ("||", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << xor_;
    ASSERT_EQ("^", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << eq_;
    ASSERT_EQ("==", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << not_eq_;
    ASSERT_EQ("!=", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << inc_;
    ASSERT_EQ("++", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << dec_;
    ASSERT_EQ("--", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << minus_;
    ASSERT_EQ("-", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << plus_;
    ASSERT_EQ("+", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << iff_;
    ASSERT_EQ("?", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << addressof_;
    ASSERT_EQ("&", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << accessto_;
    ASSERT_EQ("*", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << obj_member_;
    ASSERT_EQ(".", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << ref_member_;
    ASSERT_EQ("->", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << addressof_obj_member_;
    ASSERT_EQ(".*", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << addressof_ref_member_;
    ASSERT_EQ("->*", ss.str());
  }
}

TEST(CompilationUnit, Identifiers) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << vlocal("var1");
    ASSERT_EQ("var1", ss.str());
  }

  {
    stringstream ss;
    compilation_unit cu(ss);
    const vlocal var2 = "var1";
    cu << var2;
    ASSERT_EQ("var1", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    const vpublic var2 = "var1";
    cu << var2;
    ASSERT_EQ("var1", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    const vprotected var2 = "var1";
    cu << var2;
    ASSERT_EQ("var1_", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    const vprivate var2 = "var1";
    cu << var2;
    ASSERT_EQ("_var1__", ss.str());
  }
}

TEST(CompilationUnit, Types) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << bool_;
    ASSERT_EQ("bool", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << char_;
    ASSERT_EQ("char", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << char16_t_;
    ASSERT_EQ("char16_t", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << char32_t_;
    ASSERT_EQ("char32_t", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << float_;
    ASSERT_EQ("float", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << int_;
    ASSERT_EQ("int", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << short_;
    ASSERT_EQ("short", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << long_;
    ASSERT_EQ("long", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << signed_;
    ASSERT_EQ("signed", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << unsigned_;
    ASSERT_EQ("unsigned", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << void_;
    ASSERT_EQ("void", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << wchar_t_;
    ASSERT_EQ("wchar_t", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << vtype("myclass");
    ASSERT_EQ("myclass", ss.str());
  }
}

TEST(CompilationUnit, Directives) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << IF_;
    ASSERT_EQ("#if", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << IFDEF_;
    ASSERT_EQ("#ifdef", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << IFNDEF_;
    ASSERT_EQ("#ifndef", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << DEFINE_;
    ASSERT_EQ("#define", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << INCLUDE_;
    ASSERT_EQ("#include", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << WARNING_;
    ASSERT_EQ("#warning", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << ERROR_;
    ASSERT_EQ("#error", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << PRAGMA_;
    ASSERT_EQ("#pragma", ss.str());
  }
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << LINE_;
    ASSERT_EQ("#line", ss.str());
  }

}

TEST(CompilationUnit, LineInfoSupport) {
  {
    stringstream ss;
    stringstream result;
    compilation_unit cu(ss);
    cu << LineInfo;
    result << "#line " << __LINE__ - 1 << ' ' << '"' << __FILE__ << '"' << '\n';
    ASSERT_EQ(result.str(), ss.str());
  }
}

TEST(CompilationUnit, DirectivesMultiline) {
  {
    stringstream ss;
    compilation_unit cu(ss);
    cu << IFNDEF_ << vpublic("__TEXT__");
    cu << DEFINE_ << vpublic("__TEXT__") << 7;
    cu << ENDIF_ << vpublic("__TEXT__");
    ASSERT_EQ("#ifndef __TEXT__\n#define __TEXT__ 7\n#endif __TEXT__",
              ss.str());
  }
}

TEST(CompilationUnit, Identation) {
  {
    stringstream ss, result;
    const ::std::size_t anchor = __LINE__;
    SetupCU(ss);
    Stmt(int_ << vlocal("foo"));
    Ident {
      Stmt(float_ << vlocal("moo") << set_ << 7.1F);
    };
    result
        << "#line " << anchor + 2 << " " << '"' << __FILE__ << '"'
        << "\nint foo;\n"
        << "  #line " << anchor + 4 << " " << '"' << __FILE__ << '"'
        << "\n  float moo = 7.1;";
    ASSERT_EQ(result.str(), ss.str());
  }

}

TEST(CompilationUnit, Blocks) {
  {
    stringstream ss, result;
    const ::std::size_t anchor = __LINE__;
    SetupCU(ss);
    Stmt(int_ << vlocal("foo"));
    Block {
      Stmt(float_ << vlocal("moo") << set_ << 7.1F);
    };
    result
        << "#line " << anchor + 2 << " " << '"' << __FILE__ << '"'
        << "\nint foo; {"
        << "\n  #line " << anchor + 4 << " " << '"' << __FILE__ << '"'
        << "\n  float moo = 7.1;"
        << "\n}";
    ASSERT_EQ(result.str(), ss.str());
  }
}

#ifdef TMS2_DA_IDENTIFIERS_H
TEST(CompilationUnit, DaLiterals) {
  {
    stringstream ss, result;
    SetupCU(ss);
    const da_index_t da_entry1 = 1;
    O << da_entry1;
    ASSERT_EQ("_tms2_da_000000001", ss.str());
  }
  {
    stringstream ss, result;
    SetupCU(ss);
    const da_combinations_t da_entry1 = 1;
    O << da_entry1;
    ASSERT_EQ("_tms2_da_000000001_comb", ss.str());
  }
}
#endif
