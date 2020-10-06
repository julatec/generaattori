#ifndef GENERAATORI_TOKENS_H
#define GENERAATORI_TOKENS_H
#line 104 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
#pragma clang diagnostic push
#line 105 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#line 106 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
#pragma clang diagnostic ignored "bugprone-reserved-identifier"
#line 107 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
#pragma clang diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#include <iomanip>
#include <cstddef>
#include <iostream>
#include <new>
#include <typeinfo>
#include <functional>
#line 119 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
namespace generaattori {
  #line 120 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
  inline namespace cpp {
    #line 123 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
    typedef enum {
      bool_                         = 0,
      char_                         = 1,
      char16_t_                     = 2,
      char32_t_                     = 3,
      float_                        = 4,
      int_                          = 5,
      short_                        = 6,
      long_                         = 7,
      signed_                       = 8,
      unsigned_                     = 9,
      void_                         = 10,
      wchar_t_                      = 11,
      alignas_                      = 12,
      alignof_                      = 13,
      asm_                          = 14,
      auto_                         = 15,
      break_                        = 16,
      case_                         = 17,
      catch_                        = 18,
      class_                        = 19,
      const_                        = 20,
      constexpr_                    = 21,
      const_cast_                   = 22,
      continue_                     = 23,
      decltype_                     = 24,
      default_                      = 25,
      delete_                       = 26,
      do_                           = 27,
      double_                       = 28,
      dynamic_cast_                 = 29,
      else_                         = 30,
      enum_                         = 31,
      explicit_                     = 32,
      export_                       = 33,
      extern_                       = 34,
      final_                        = 35,
      for_                          = 36,
      friend_                       = 37,
      goto_                         = 38,
      if_                           = 39,
      inline_                       = 40,
      mutable_                      = 41,
      namespace_                    = 42,
      new_                          = 43,
      noexcept_                     = 44,
      nullptr_                      = 45,
      operator_                     = 46,
      override_                     = 47,
      private_                      = 48,
      protected_                    = 49,
      public_                       = 50,
      register_                     = 51,
      reinterpret_cast_             = 52,
      return_                       = 53,
      sizeof_                       = 54,
      static_                       = 55,
      static_assert_                = 56,
      static_cast_                  = 57,
      struct_                       = 58,
      switch_                       = 59,
      template_                     = 60,
      this_                         = 61,
      thread_local_                 = 62,
      throw_                        = 63,
      try_                          = 64,
      typedef_                      = 65,
      typeid_                       = 66,
      typename_                     = 67,
      union_                        = 68,
      using_                        = 69,
      virtual_                      = 70,
      volatile_                     = 71,
      while_                        = 72,
      set_                          = 73,
      sum_eq_                       = 74,
      sub_eq_                       = 75,
      mul_eq_                       = 76,
      div_eq_                       = 77,
      mod_eq_                       = 78,
      or_eq_                        = 79,
      and_eq_                       = 80,
      xor_eq_                       = 81,
      rshift_eq_                    = 82,
      lshift_eq_                    = 83,
      sum_                          = 84,
      sub_                          = 85,
      mul_                          = 86,
      div_                          = 87,
      mod_                          = 88,
      bitor_                        = 89,
      bitand_                       = 90,
      rshift_                       = 91,
      lshift_                       = 92,
      compl_                        = 93,
      not_                          = 94,
      and_                          = 95,
      or_                           = 96,
      xor_                          = 97,
      eq_                           = 98,
      not_eq_                       = 99,
      inc_                          = 100,
      dec_                          = 101,
      minus_                        = 102,
      plus_                         = 103,
      iff_                          = 104,
      addressof_                    = 105,
      accessto_                     = 106,
      obj_member_                   = 107,
      ref_member_                   = 108,
      addressof_obj_member_         = 109,
      addressof_ref_member_         = 110,
      gt_                           = 111,
      lt_                           = 112,
      gte_                          = 113,
      lte_                          = 114,
      IF_                           = 115,
      IFDEF_                        = 116,
      IFNDEF_                       = 117,
      ENDIF_                        = 118,
      DEFINE_                       = 119,
      INCLUDE_                      = 120,
      WARNING_                      = 121,
      ERROR_                        = 122,
      PRAGMA_                       = 123,
      LINE_                         = 124,
      identifier_                   = 125,
      blank_                        = 126,
      nl_                           = 127,
      line_comment_                 = 128,
      block_comment_                = 129,
      s_                            = 130,
      sm_                           = 131,
      cl_                           = 132,
      sc_                           = 133
      } cpp_token_t;
    #line 137 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
    typedef enum {
      blank                        = 0,
      punctuation                  = 1,
      word                         = 2
      } cpp_token_categories_t;
    #line 155 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
    template <typename _CharT,
    typename _TraitsT>::std::basic_ostream<_CharT, _TraitsT>&operator <<(::std::basic_ostream<_CharT, _TraitsT>&os,
    const cpp_token_t&t) {
      #line 162 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
      switch(t) {
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case bool_:
          return os << 'b' << 'o' << 'o' << 'l';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case char_:
          return os << 'c' << 'h' << 'a' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case char16_t_:
          return os << 'c' << 'h' << 'a' << 'r' << '1' << '6' << '_' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case char32_t_:
          return os << 'c' << 'h' << 'a' << 'r' << '3' << '2' << '_' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case float_:
          return os << 'f' << 'l' << 'o' << 'a' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case int_:
          return os << 'i' << 'n' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case short_:
          return os << 's' << 'h' << 'o' << 'r' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case long_:
          return os << 'l' << 'o' << 'n' << 'g';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case signed_:
          return os << 's' << 'i' << 'g' << 'n' << 'e' << 'd';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case unsigned_:
          return os << 'u' << 'n' << 's' << 'i' << 'g' << 'n' << 'e' << 'd';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case void_:
          return os << 'v' << 'o' << 'i' << 'd';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case wchar_t_:
          return os << 'w' << 'c' << 'h' << 'a' << 'r' << '_' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case alignas_:
          return os << 'a' << 'l' << 'i' << 'g' << 'n' << 'a' << 's';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case alignof_:
          return os << 'a' << 'l' << 'i' << 'g' << 'n' << 'o' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case asm_:
          return os << 'a' << 's' << 'm';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case auto_:
          return os << 'a' << 'u' << 't' << 'o';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case break_:
          return os << 'b' << 'r' << 'e' << 'a' << 'k';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case case_:
          return os << 'c' << 'a' << 's' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case catch_:
          return os << 'c' << 'a' << 't' << 'c' << 'h';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case class_:
          return os << 'c' << 'l' << 'a' << 's' << 's';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case const_:
          return os << 'c' << 'o' << 'n' << 's' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case constexpr_:
          return os << 'c' << 'o' << 'n' << 's' << 't' << 'e' << 'x' << 'p' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case const_cast_:
          return os << 'c' << 'o' << 'n' << 's' << 't' << '_' << 'c' << 'a' << 's' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case continue_:
          return os << 'c' << 'o' << 'n' << 't' << 'i' << 'n' << 'u' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case decltype_:
          return os << 'd' << 'e' << 'c' << 'l' << 't' << 'y' << 'p' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case default_:
          return os << 'd' << 'e' << 'f' << 'a' << 'u' << 'l' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case delete_:
          return os << 'd' << 'e' << 'l' << 'e' << 't' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case do_:
          return os << 'd' << 'o';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case double_:
          return os << 'd' << 'o' << 'u' << 'b' << 'l' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case dynamic_cast_:
          return os << 'd' << 'y' << 'n' << 'a' << 'm' << 'i' << 'c' << '_' << 'c' << 'a' << 's' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case else_:
          return os << 'e' << 'l' << 's' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case enum_:
          return os << 'e' << 'n' << 'u' << 'm';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case explicit_:
          return os << 'e' << 'x' << 'p' << 'l' << 'i' << 'c' << 'i' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case export_:
          return os << 'e' << 'x' << 'p' << 'o' << 'r' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case extern_:
          return os << 'e' << 'x' << 't' << 'e' << 'r' << 'n';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case final_:
          return os << 'f' << 'i' << 'n' << 'a' << 'l';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case for_:
          return os << 'f' << 'o' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case friend_:
          return os << 'f' << 'r' << 'i' << 'e' << 'n' << 'd';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case goto_:
          return os << 'g' << 'o' << 't' << 'o';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case if_:
          return os << 'i' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case inline_:
          return os << 'i' << 'n' << 'l' << 'i' << 'n' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case mutable_:
          return os << 'm' << 'u' << 't' << 'a' << 'b' << 'l' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case namespace_:
          return os << 'n' << 'a' << 'm' << 'e' << 's' << 'p' << 'a' << 'c' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case new_:
          return os << 'n' << 'e' << 'w';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case noexcept_:
          return os << 'n' << 'o' << 'e' << 'x' << 'c' << 'e' << 'p' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case nullptr_:
          return os << 'n' << 'u' << 'l' << 'l' << 'p' << 't' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case operator_:
          return os << 'o' << 'p' << 'e' << 'r' << 'a' << 't' << 'o' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case override_:
          return os << 'o' << 'v' << 'e' << 'r' << 'r' << 'i' << 'd' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case private_:
          return os << 'p' << 'r' << 'i' << 'v' << 'a' << 't' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case protected_:
          return os << 'p' << 'r' << 'o' << 't' << 'e' << 'c' << 't' << 'e' << 'd';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case public_:
          return os << 'p' << 'u' << 'b' << 'l' << 'i' << 'c';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case register_:
          return os << 'r' << 'e' << 'g' << 'i' << 's' << 't' << 'e' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case reinterpret_cast_:
          return os << 'r' << 'e' << 'i' << 'n' << 't' << 'e' << 'r' << 'p' << 'r' << 'e' << 't' << '_' << 'c' << 'a' << 's' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case return_:
          return os << 'r' << 'e' << 't' << 'u' << 'r' << 'n';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sizeof_:
          return os << 's' << 'i' << 'z' << 'e' << 'o' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case static_:
          return os << 's' << 't' << 'a' << 't' << 'i' << 'c';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case static_assert_:
          return os << 's' << 't' << 'a' << 't' << 'i' << 'c' << '_' << 'a' << 's' << 's' << 'e' << 'r' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case static_cast_:
          return os << 's' << 't' << 'a' << 't' << 'i' << 'c' << '_' << 'c' << 'a' << 's' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case struct_:
          return os << 's' << 't' << 'r' << 'u' << 'c' << 't';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case switch_:
          return os << 's' << 'w' << 'i' << 't' << 'c' << 'h';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case template_:
          return os << 't' << 'e' << 'm' << 'p' << 'l' << 'a' << 't' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case this_:
          return os << 't' << 'h' << 'i' << 's';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case thread_local_:
          return os << 't' << 'h' << 'r' << 'e' << 'a' << 'd' << '_' << 'l' << 'o' << 'c' << 'a' << 'l';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case throw_:
          return os << 't' << 'h' << 'r' << 'o' << 'w';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case try_:
          return os << 't' << 'r' << 'y';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case typedef_:
          return os << 't' << 'y' << 'p' << 'e' << 'd' << 'e' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case typeid_:
          return os << 't' << 'y' << 'p' << 'e' << 'i' << 'd';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case typename_:
          return os << 't' << 'y' << 'p' << 'e' << 'n' << 'a' << 'm' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case union_:
          return os << 'u' << 'n' << 'i' << 'o' << 'n';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case using_:
          return os << 'u' << 's' << 'i' << 'n' << 'g';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case virtual_:
          return os << 'v' << 'i' << 'r' << 't' << 'u' << 'a' << 'l';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case volatile_:
          return os << 'v' << 'o' << 'l' << 'a' << 't' << 'i' << 'l' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case while_:
          return os << 'w' << 'h' << 'i' << 'l' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case set_:
          return os << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sum_eq_:
          return os << '+' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sub_eq_:
          return os << '-' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case mul_eq_:
          return os << '*' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case div_eq_:
          return os << '/' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case mod_eq_:
          return os << '%' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case or_eq_:
          return os << '|' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case and_eq_:
          return os << '&' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case xor_eq_:
          return os << '^' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case rshift_eq_:
          return os << '>' << '>' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case lshift_eq_:
          return os << '<' << '<' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sum_:
          return os << '+';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sub_:
          return os << '-';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case mul_:
          return os << '*';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case div_:
          return os << '/';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case mod_:
          return os << '%';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case bitor_:
          return os << '|';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case bitand_:
          return os << '&';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case rshift_:
          return os << '>' << '>';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case lshift_:
          return os << '<' << '<';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case compl_:
          return os << '~';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case not_:
          return os << '!';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case and_:
          return os << '&' << '&';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case or_:
          return os << '|' << '|';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case xor_:
          return os << '^';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case eq_:
          return os << '=' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case not_eq_:
          return os << '!' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case inc_:
          return os << '+' << '+';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case dec_:
          return os << '-' << '-';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case minus_:
          return os << '-';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case plus_:
          return os << '+';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case iff_:
          return os << '?';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case addressof_:
          return os << '&';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case accessto_:
          return os << '*';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case obj_member_:
          return os << '.';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case ref_member_:
          return os << '-' << '>';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case addressof_obj_member_:
          return os << '.' << '*';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case addressof_ref_member_:
          return os << '-' << '>' << '*';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case gt_:
          return os << '>';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case lt_:
          return os << '<';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case gte_:
          return os << '<' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case lte_:
          return os << '>' << '=';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case IF_:
          return os << '#' << 'i' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case IFDEF_:
          return os << '#' << 'i' << 'f' << 'd' << 'e' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case IFNDEF_:
          return os << '#' << 'i' << 'f' << 'n' << 'd' << 'e' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case ENDIF_:
          return os << '#' << 'e' << 'n' << 'd' << 'i' << 'f';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case DEFINE_:
          return os << '#' << 'd' << 'e' << 'f' << 'i' << 'n' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case INCLUDE_:
          return os << '#' << 'i' << 'n' << 'c' << 'l' << 'u' << 'd' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case WARNING_:
          return os << '#' << 'w' << 'a' << 'r' << 'n' << 'i' << 'n' << 'g';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case ERROR_:
          return os << '#' << 'e' << 'r' << 'r' << 'o' << 'r';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case PRAGMA_:
          return os << '#' << 'p' << 'r' << 'a' << 'g' << 'm' << 'a';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case LINE_:
          return os << '#' << 'l' << 'i' << 'n' << 'e';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case s_:
          return os << ',';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sm_:
          return os << ';';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case cl_:
          return os << ':';
        #line 167 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        case sc_:
          return os << ':' << ':';
        #line 177 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
        default:
          #line 178 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
          break;
      }
      #line 181 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
      return os;
    }
    #line 183 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
    constexpr const cpp_token_categories_t category_of [ 134UL] = {
    #line 186 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    punctuation,
    punctuation,
    word,
    word,
    word,
    word,
    word,
    punctuation,
    punctuation,
    word,
    word,
    word,
    punctuation,
    punctuation,
    punctuation,
    punctuation,
    punctuation,
    punctuation,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    word,
    blank,
    blank,
    blank,
    blank,
    punctuation,
    punctuation,
    punctuation,
    punctuation};
  }
}
#line 193 "/home/julatec/Workspace/generaattori-cpp/src/cpp/cpp2h.cpp"
#pragma clang diagnostic pop
#endif