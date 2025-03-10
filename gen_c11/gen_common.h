#if INTELLISENSE_DIRECTIVES
#	pragma once
#endif

#define GEN_DONT_ENFORCE_GEN_TIME_GUARD
#define GEN_DEFINE_LIBRARY_CODE_CONSTANTS
#define GEN_ENFORCE_STRONG_CODE_TYPES
#define GEN_IMPLEMENTATION
#include "third_party/gencpp_c11/gencpp_c11.h"
#include "third_party/gencpp_c11/misc.h"

#include "third_party/gencpp_c11/push_ignores.inline.h"

#define path_root            "./"
#define path_bin             path_root     "bin/"
#define path_build           path_root     "build/"
#define path_metadesk        path_root     "metadesk/"
#define path_source          path_metadesk "source/"
#define path_gen_c11         path_root     "gen_c11/"
#define path_gen             path_gen_c11  "gen/"
#define path_base            path_source   "base/"
#define path_mdesk           path_source   "mdesk/"
#define path_os              path_source   "os/"
#define path_os_win32        path_os       "win32/"
#define path_os_linux        path_os       "linux/"
#define path_third_party     path_root     "third_party/"
#define path_md_third_party  path_metadesk "third_party/"
#define path_scratch_file    path_gen      "scratch.h"
#define path_format_style    path_bin      ".clang-format "

#define gen_iterator( Type, container, iter )   \
	        gen_begin_ ## Type(container);      \
	iter != gen_end_   ## Type(container);      \
	iter  = gen_next_  ## Type(container, iter)

// Codegen DSL

#define lit     gen_txt
#define nullptr gen_nullptr
// #define args    

#define str_fmt(fmt, ...)           gen_strbuilder_to_str(gen_strbuilder_fmt_buf(gen_get_context()->Allocator_Temp, fmt, __VA_ARGS__))
#define print(code)                 gen_builder_print(builder, code);
#define print_fmt(fmt, ...)         gen_builder_print_fmt(builder, fmt, __VA_ARGS__)
#define new_line()                  gen_builder_print(builder, gen_fmt_newline)
#define pragma_region(label)        print(gen_def_pragma(str_fmt("region %S",    lit(label))))
#define pragma_endregion(label)     print(gen_def_pragma(str_fmt("endregion %S", lit(label))))
#define define(id, type, ...)       print(gen_def__define(id, type, &(gen_Opts_def_define){ __VA_ARGS__ }))
#define comment(content)            print(gen_def_comment(lit(content)))
#define include(content, ...)       print(gen_def__include(content, &(gen_Opts_def_include){ __VA_ARGS__}))
#define preprocess_cond(type, expr) gen_def_preprocess_cond(type, expr)
#define preprocess_if(expr)         print(preprocess_cond(PreprocessCond_If,       lit(expr))); new_line()
#define preprocess_ifndef(expr)     print(preprocess_cond(PreprocessCond_IfNotDef, lit(expr))); new_line()
#define preprocess_elif(expr)       print(preprocess_cond(PreprocessCond_ElIf,     lit(expr))); new_line()
#define preprocess_endif()		    print(gen_preprocess_endif)

#ifndef PRINT_SECTION_REGION_PRAGMAS
#define PRINT_SECTION_REGION_PRAGMAS 1
#endif

#define print_section(code, label) print__section(builder, code, label)
void print__section(gen_Builder* builder, gen_Code code, gen_Str label) {
	if (PRINT_SECTION_REGION_PRAGMAS) gen_builder_print(builder, gen_def_pragma(str_fmt("region %S", label)) );
	gen_builder_print(builder, code);
	if (PRINT_SECTION_REGION_PRAGMAS) gen_builder_print(builder, gen_def_pragma(str_fmt("endregion %S", label)) );
	gen_builder_print(builder, gen_fmt_newline);
}

void register_library_macros() 
{
	// third_party/stb/stb_sprintf.h
	gen_register_macros( args(
		((gen_Macro) { lit("STB_SPRINTF_H_INCLUDE"),   MT_Statement,  }),
		((gen_Macro) { lit("STBSP__ASAN"),             MT_Statement,                  MF_Allow_As_Attribute }),
		((gen_Macro) { lit("STBSP__PUBLICDEC"),        MT_Expression,                 MF_Allow_As_Attribute }),
		((gen_Macro) { lit("STBSP__ATTRIBUTE_FORMAT"), MT_Expression, MF_Functional | MF_Allow_As_Attribute }),
		((gen_Macro) { lit("STBSP__NOTUSED"),          MT_Expression, MF_Functional | MF_Allow_As_Attribute }),
		((gen_Macro) { lit("STBSP__NOTUSED"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("STB_SPRINTF_MIN"),         MT_Expression,                 MF_Allow_As_Identifier }),
		((gen_Macro) { lit("STB_SPRINTF_DECORATE"),    MT_Expression, MF_Functional | MF_Allow_As_Identifier | MF_Identifier_Decorator }),
		((gen_Macro) { lit("STB_SPRINTF_MSVC_MODE"),   MT_Expression,  }),
		((gen_Macro) { lit("STBSP__PUBLICDEF"),        MT_Expression,                 MF_Allow_As_Attribute }),
		((gen_Macro) { lit("STBSP__UNALIGNED"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("STBSP__SPECIAL"),          MT_Expression,  }),
		((gen_Macro) { lit("STBSP__LEFTJUST"),         MT_Expression,  }),
		((gen_Macro) { lit("STBSP__LEADINGPLUS"),      MT_Expression,  }),
		((gen_Macro) { lit("STBSP__LEADINGSPACE"),     MT_Expression,  }),
		((gen_Macro) { lit("STBSP__LEADING_0X"),       MT_Expression,  }),
		((gen_Macro) { lit("STBSP__LEADINGZERO"),      MT_Expression,  }),
		((gen_Macro) { lit("STBSP__INTMAX"),           MT_Expression,  }),
		((gen_Macro) { lit("STBSP__TRIPLET_COMMA"),    MT_Expression,  }),
		((gen_Macro) { lit("STBSP__NEGATIVE"),         MT_Expression,  }),
		((gen_Macro) { lit("STBSP__METRIC_SUFFIX"),    MT_Expression,  }),
		((gen_Macro) { lit("STBSP__HALFWIDTH"),        MT_Expression,  }),
		((gen_Macro) { lit("STBSP__METRIC_NOSPACE"),   MT_Expression,  }),
		((gen_Macro) { lit("STBSP__METRIC_1024"),      MT_Expression,  }),
		((gen_Macro) { lit("STBSP__METRIC_JEDEC"),     MT_Expression,  }),
		((gen_Macro) { lit("stbsp__chk_cb_bufL"),      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__chk_cb_buf"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__flush_cb"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__cb_buf_clamp"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("STBSP__NUMSZ"),            MT_Expression, }),
		((gen_Macro) { lit("STBSP__COPYFP"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__tento19th"),        MT_Expression,  }),
		((gen_Macro) { lit("stbsp__ddmulthi"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__ddrenorm"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__ddmultlo"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__ddmultlos"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("stbsp__ddtoS64"),          MT_Expression, MF_Functional })
	));

	// These in the same order as metadesk.h

	// base/context_cracking.h
	gen_register_macros( args(
		((gen_Macro) { lit("MD_BUILD_DEBUG"),                          MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_STATIC"),                         MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_DYNAMIC"),                        MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_API_EXPORT"),                     MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_ENTRY_DEFINING_UNIT"),            MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_CONSOLE_INTERFACE"),              MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_VERSION_MAJOR"),                  MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_VERSION_MINOR"),                  MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_VERSION_PATCH"),                  MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_VERSION_STRING_LITERAL"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_MODE_STRING_LITERAL_APPEND"),     MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_GIT_HASH_STRING_LITERAL_APPEND"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_TITLE"),                          MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_RELEASE_PHASE_STRING_LITERAL"),   MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_ISSUES_LINK_STRING_LITERAL"),     MT_Expression,  }),
		((gen_Macro) { lit("MD_BUILD_TITLE_STRING_LITERAL"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_COMPILER_MSVC"),                        MT_Expression,  }),
		((gen_Macro) { lit("MD_COMPILER_CLANG"),                       MT_Expression,  }),
		((gen_Macro) { lit("MD_COMPILER_GCC"),                         MT_Expression,  }),
		((gen_Macro) { lit("MD_LANG_C"),                               MT_Expression,  }),
		((gen_Macro) { lit("MD_LANG_CPP"),                             MT_Expression,  }),
		((gen_Macro) { lit("MD_ARCH_X64"),                             MT_Expression,  }),
		((gen_Macro) { lit("MD_ARCH_X86"),                             MT_Expression,  }),
		((gen_Macro) { lit("MD_ARCH_ARM64"),                           MT_Expression,  }),
		((gen_Macro) { lit("MD_ARCH_ARM32"),                           MT_Expression,  }),
		((gen_Macro) { lit("MD_ARCH_LITTLE_ENDIAN"),                   MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_WINDOWS"),                           MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_OSX"),                               MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_ANDROID"),                           MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_LINUX"),                             MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_FREEBSD"),                           MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_OPENBSD"),                           MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_EMSCRIPTEN"),                        MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_CYGWIN"),                            MT_Expression,  }),
		((gen_Macro) { lit("MD_API"),                                  MT_Expression,  MF_Allow_As_Attribute }),
		((gen_Macro) { lit("MD_API_C"),                                MT_Expression,  MF_Allow_As_Attribute }),
		((gen_Macro) { lit("MD_API_C_BEGIN"),                          MT_Statement,                         }),
		((gen_Macro) { lit("MD_API_C_END"),                            MT_Statement,                         })
	));
	// base/macros.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_expect"),                               MT_Expression, MF_Functional | MF_Allow_As_Attribute }),
		((gen_Macro) { lit("md_likely"),                               MT_Expression, MF_Functional | MF_Allow_As_Attribute }),
		((gen_Macro) { lit("md_unlikely"),                             MT_Expression, MF_Functional | MF_Allow_As_Attribute }),
		((gen_Macro) { lit("md_ccast"),                                MT_Expression, MF_Functional                         }),
		((gen_Macro) { lit("md_rcast"),                                MT_Expression, MF_Functional                         }),
		((gen_Macro) { lit("md_pcast"),                                MT_Expression, MF_Functional                         }),
		((gen_Macro) { lit("md_scast"),                                MT_Expression, MF_Functional                         }),
		((gen_Macro) { lit("md_typeof"),                               MT_Expression,  }),
		((gen_Macro) { lit("md_nullptr"),                              MT_Expression,  }),
		((gen_Macro) { lit("md_defer_loop"),                           MT_Statement,  MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_defer_loop_checked"),                   MT_Statement,  MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_each_enum_val"),                        MT_Statement,  MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_each_non_zero_enum_val"),               MT_Statement,  MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_stringify"),                            MT_Expression, MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_glue"),                                 MT_Expression, MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_src_line_str"),                         MT_Expression,  }),
		((gen_Macro) { lit("md_do_once"),                              MT_Statement,  MF_Functional | MF_Expects_Body }),
		((gen_Macro) { lit("md_do_once_start"),                        MT_Statement,  }),
		((gen_Macro) { lit("md_do_once_end"),                          MT_Statement,  }),
		((gen_Macro) { lit("md_do_once_end"),                          MT_Statement,  })
	));
	// base/generic_macros.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_COMMA_OPERATOR"),                           MT_Expression, }),
		((gen_Macro) { lit("md_select_arg_1"),                             MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_select_arg_2"),                             MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_select_arg_3"),                             MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_generic_sel_entry_type"),                   MT_Expression,                }),
		((gen_Macro) { lit("md_generic_sel_entry_function"),               MT_Expression,                }),
		((gen_Macro) { lit("md_generic_sel_entry_comma_delimiter"),        MT_Expression,                }),
		((gen_Macro) { lit("md_generic_call"),                             MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_if_generic_selector_defined_include_slot"), MT_Expression,                }),
		((gen_Macro) { lit("md_function_generic_example"),                 MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("MD_GENERIC_SLOT_1__example_hash"),             MT_Expression,                }),
		((gen_Macro) { lit("MD_GENERIC_SLOT_2__example_hash"),             MT_Expression,                }),
		((gen_Macro) { lit("md_generic_example_hash"),                     MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_function_generic_example_varadic"),         MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_function_generic_example_direct_type"),     MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("md_type_to_expression"),                       MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("_Generic_L2"),                                 MT_Expression, MF_Functional  }),
		((gen_Macro) { lit("_Generic_L3"),                                 MT_Expression, MF_Functional  })
	));
	// base/profiling.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_PROFILE_TELEMETRY"),    MT_Expression,               }),
		((gen_Macro) { lit("MD_MARKUP_LAYER_COLOR"),   MT_Expression,               }),
		((gen_Macro) { lit("md_prof_begin"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_begin_dynamic"),   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_end"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_tick"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_is_capturing"),    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_begin_capture"),   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_end_capture"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_thread_name"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_msg"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_begin_lock_wait"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_end_lock_wait"),   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_lock_take"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_lock_drop"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_color"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_msg"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_begin_function"),  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_scope"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_prof_scope"),           MT_Expression, MF_Functional }),
	));
	// base/base_types.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_size_of"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_SIGN32"),            MT_Expression,  }),
		((gen_Macro) { lit("MD_EXPONENT32"),        MT_Expression,  }),
		((gen_Macro) { lit("MD_MANTISSA32"),        MT_Expression,  }),
		((gen_Macro) { lit("MD_BIG_GOLDEN32"),      MT_Expression,  }),
		((gen_Macro) { lit("MD_SMALL_GOLDEN32"),    MT_Expression,  }),
		((gen_Macro) { lit("MD_PI32"),              MT_Expression,  }),
		((gen_Macro) { lit("MD_MACHINE_EPSILON64"), MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_U8"),            MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_U8"),            MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_S8"),            MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_S8"),            MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_U16"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_U16"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_S16"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_S16"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_U32"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_U32"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_S32"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_U64"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_U64"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_S64"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_S64"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_USIZE"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_USIZE"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_SSIZE"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_SSIZE"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_F32"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_F32"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MIN_F64"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_MAX_F64"),           MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK1"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK2"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK3"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK4"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK5"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK6"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK7"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK8"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK9"),          MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK10"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK11"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK12"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK13"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK14"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK15"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK16"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK17"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK18"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK19"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK20"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK21"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK22"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK23"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK24"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK25"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK26"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK27"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK28"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK29"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK30"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK31"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK32"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK33"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK34"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK35"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK36"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK37"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK38"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK39"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK40"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK41"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK42"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK43"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK44"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK45"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK46"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK47"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK48"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK49"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK50"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK51"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK52"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK53"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK54"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK55"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK56"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK57"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK58"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK59"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK60"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK61"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK62"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK63"),         MT_Expression,  }),
		((gen_Macro) { lit("MD_BITMASK64"),         MT_Expression,  })
	));
	gen_register_macros(args(
		((gen_Macro) { lit("MD_BIT1"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT2"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT3"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT4"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT5"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT6"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT7"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT8"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT9"),  MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT10"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT11"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT12"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT13"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT14"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT15"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT16"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT17"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT18"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT19"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT20"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT21"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT22"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT23"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT24"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT25"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT26"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT27"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT28"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT29"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT30"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT31"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT32"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT33"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT34"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT35"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT36"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT37"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT38"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT39"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT40"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT41"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT42"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT43"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT44"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT45"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT46"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT47"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT48"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT49"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT50"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT51"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT52"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT53"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT54"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT55"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT56"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT57"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT58"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT59"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT60"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT61"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT62"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT63"), MT_Expression,  }),
		((gen_Macro) { lit("MD_BIT64"), MT_Expression,  })
	));
	// base/ring.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_ring_write_struct"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ring_read_struct"),  MT_Expression, MF_Functional })
	));
	// base/debug.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_trap"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_assert_msg"),      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_assert_always"),   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_assert"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_invalid_path"),    MT_Expression, }),
		((gen_Macro) { lit("md_not_implemented"), MT_Expression, }),
		((gen_Macro) { lit("md_no_op"),           MT_Expression, }),
		((gen_Macro) { lit("md_static_assert"),   MT_Expression, MF_Functional })
	));
	// base/memory.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_KILOBYTES"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_MEGABYTES"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_GIGABYTES"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_TERABYTES"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_KB"),                               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_MB"),                               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_GB"),                               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_TB"),                               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_thousand"),                         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_million"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_billion"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_align_of"),                         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_member"),                           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_offset_of"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_member_from_offset"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_cast_from_member"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_cast_from_member"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_copy"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_set"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_compare"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_str_len"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_copy_struct"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_copy_array"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_copy_type"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_zero"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_zero_struct"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_zero_array"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_zero_type"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_match"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_match_struct"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_match_array"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_read"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_memory_consume"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u64_eval"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u64_inc_eval"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u64_dec_eval"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u64_eval_assign"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u64_add_eval"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u64_eval_cond_assign"),  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u32_eval"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u32_eval_assign"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ins_atomic_u32_eval_cond_assign"),  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_check_nil"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_set_nil"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_LINKED_LIST_PURE_MACRO"),           MT_Expression,  }),
		((gen_Macro) { lit("md_dll_insert_npz"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_push_back_npz"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_push_front_npz"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_remove_npz"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_push_nz"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_push_front_nz"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_pop_nz"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_stack_push_n"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_stack_pop_n"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_insert_np"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_push_back_np"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_push_front_np"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_remove_np"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_insert"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_push_back"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_push_front"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dll_remove"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_push_n"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_push_front_n"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_pop_n"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_push"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_push_front"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_queue_pop"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_stack_push"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sll_stack_pop"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_NO_ASAN"),                          MT_Expression,  }),
		((gen_Macro) { lit("MD_MD_ASAN_ENABLED"),                  MT_Expression,  }),
		((gen_Macro) { lit("md_asan_poison_memory_region"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_asan_unpoison_memory_region"),      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_array_count"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ceil_integer_div"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_swap"),                             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_int_from_ptr"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ptr_from_int"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_compose_64bit"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_align_pow2"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_align_down_pow2"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_align_pad_pow2"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_is_pow2"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_is_pow2_or_zero"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_extract_bit"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_zero_struct"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_this_function_name"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_read_only"),                        MT_Expression, MF_Functional | MF_Allow_As_Specifier }),
		((gen_Macro) { lit("md_thread_static"),                    MT_Expression, MF_Allow_As_Specifier }),
		((gen_Macro) { lit("md_from_be_u16"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_from_be_u32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_from_be_u64"),                      MT_Expression, MF_Functional })
	));
	// base/memory_substrate.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD__ONES"),                    MT_Expression,  }),
		((gen_Macro) { lit("MD__HIGHS"),                   MT_Expression,  }),
		((gen_Macro) { lit("MD__HAS_ZERO"),                MT_Expression,  }),
		((gen_Macro) { lit("MD_DEFAULT_MEMORY_ALIGNMENT"), MT_Expression,  }),
		((gen_Macro) { lit("MD_HEAP_ANALYSIS"),            MT_Expression,  }),
		((gen_Macro) { lit("md_heap"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_md_malloc"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_md_free"),                  MT_Expression,  }),
		((gen_Macro) { lit("md_VARENA_DEFUALT_RESERVE"),   MT_Expression,  }),
		((gen_Macro) { lit("md_VARENA_DEFUALT_COMMIT"),    MT_Expression,  }),
		((gen_Macro) { lit("md_varena_alloc"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_varena_allocator"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_farena_from_byteslice"),    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_farena_from_memory"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_farena_allocator"),         MT_Expression, MF_Functional })
	));
	// base/arena.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_ARENA_DEFAULT_BLOCK_SIZE"),   MT_Expression,  }),
		((gen_Macro) { lit("md_arena_alloc"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_push_array_no_zero_aligned"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_push_array_aligned"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_push_array_no_zero"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_push_array"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("MD_OVERRIDE_DEFAULT_ALLOCATOR"), MT_Expression,  })
	));
	// base/math.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_min"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_max"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_clamp_top"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_clamp_bot"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_clamp"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_abs_s64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sqrt_f32"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mod_f32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_pow_f32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ceil_f32"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_floor_f32"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_round_f32"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_abs_f32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_radians_from_turns_f32"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_turns_from_radians_f32"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_degrees_from_turns_f32"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_turns_from_degrees_f32"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_degrees_from_radians_f32"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_radians_from_degrees_f32"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sin_f32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_cos_f32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_tan_f32"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sqrt_f64"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mod_f64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_pow_f64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_ceil_f64"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_floor_f64"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_round_f64"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_abs_f64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_radians_from_turns_f64"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_turns_from_radians_f64"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_degrees_from_turns_f64"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_turns_from_degrees_f64"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_degrees_from_radians_f64"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_radians_from_degrees_f64"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sin_f64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_cos_f64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_tan_f64"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v2f32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v2s64"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v2s32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v2s16"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_vec2"),                         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_add_vec2"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sub_vec2"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mul_vec2"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_div_vec2"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_scale_vec2"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dot_vec2"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_length_squared_vec2"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_length_vec2"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_normalize_vec2"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mix_vec2"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v3f32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v3s32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_vec3"),                         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_add_vec3"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sub_vec3"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mul_vec3"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_div_vec3"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_scale_vec3"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dot_vec3"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_length_squared_vec3"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_length_vec3"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_normalize_vec3"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mix_vec3"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_cross_vec3"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v4f32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_v4s32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_vec4"),                         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_add_vec4"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_sub_vec4"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mul_vec4"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_div_vec4"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_scale_vec4"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_dot_vec4"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_length_squared_vec4"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_length_vec4"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_normalize_vec4"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_mix_vec4"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r1u32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r1s32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r1u64"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r1s64"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r1f32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r2s16"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r2s16p"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r2s32"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r2s32p"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r2s64"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_r2s64p"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_rgba_from_u32_lit_comp"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_rng1s64_list_push"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_rng1s64_array_from_list_push"), MT_Expression, MF_Functional })
	));
	// base/sort.h
	gen_register_macro((gen_Macro) { lit("md_quick_sort"), MT_Expression, MF_Functional });
	// base/strings.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_cstring_length"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_lit"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_lit_comp"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_varg"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_array"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_array_fixed"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_struct"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str_range"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str_cstring"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_cat"),                        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_copy"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8fv"),                          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8f"),                           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_upper_from_str8"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_lower_from_str8"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_backslashed_from_str8"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_match_lit"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_match_cstr"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_ends_with_lit"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_memory_size"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_u64"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_s64"),                   MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_bits_u32"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_bits_u64"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_first"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_aligner"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_copy"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_push"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_push_front"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_pushf"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_push_frontf"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_split"),                      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_split_by_string_chars"),      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_split_by_string_chars"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_list_join"),                  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_array_from_list"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_array_reserve"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_split_path"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_path_list_join_by_style"),    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_str16"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str16_from_str8"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from_str32"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str32_from_str8"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_date_time_string"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_file_name_date_time_string"),      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_string_from_elapsed_time"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_string_from_guid"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_indented_from_string"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_escaped_from_raw_str8"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_raw_from_escaped_str8"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_wrapped_lines_from_string"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_hex_string_from_rgba_4f32"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_fuzzy_match_find"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_fuzzy_match_range_list_copy"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_array"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_struct"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_begin"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_end"),                 MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_align"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_size"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_data"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_data_list"),      MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_u64"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_u32"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_u16"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_u8"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_cstr"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_serial_push_string"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_deserial_read_array"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_deserial_read_struct"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str8_from"),                       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_str16_from"),                      MT_Expression, MF_Functional })
	));
	// base/thread_context.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_tctx_write_this_srcloc"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_scratch_begin"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_scratch_end"),            MT_Expression, MF_Functional })
	));
	// base/command_line.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_cmd_line_insert_opt"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_cmd_line_from_string_list"), MT_Expression, MF_Functional })
	));
	// base/markup.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_thread_namef"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_thread_name"),  MT_Expression, MF_Functional })
	));
	// base/logger.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_LOG_DEFAULT_ARENA_BLOCK_SIZE"), MT_Expression,  }),
		((gen_Macro) { lit("md_log_info"),                     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_infof"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_user_error"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_user_errorf"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_info_named_block"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_info_named_blockf"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_scope_begin"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_log_scope_end"),                MT_Expression, MF_Functional })
	));


	// os/os.h
	gen_register_macros(args(
		((gen_Macro) { lit("md_os_handle_ist_push"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_handle_array_from_list"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_string_list_from_argcv"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_full_path_from_path"),    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_file_iter_begin"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_data_from_file_path"),    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_string_from_file_range"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_string_from_guid"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_get_current_path"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_mutex_scope"),            MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_mutex_scope_r"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_mutex_scope_W"),          MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_os_mutex_scope_rw_promote"), MT_Expression, MF_Functional })
	));
	// os/os_resolve.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_OS_FEATURE_GRAPHICAL"), MT_Expression,  }),
		((gen_Macro) { lit("MD_OS_GFX_STUB"),          MT_Expression,  })
	));
	// os/win32/os_win32_includes.h
	gen_register_macros(args(
		((gen_Macro) { lit("NOMINMAX"),            MT_Expression,  }),
		((gen_Macro) { lit("WIN32_LEAN_AND_MEAN"), MT_Expression,  }),
		((gen_Macro) { lit("WIN32_MEAN_AND_LEAN"), MT_Expression,  }),
		((gen_Macro) { lit("VC_EXTRALEAN"),        MT_Expression,  })
	));
	// os/linux/os_linux_includes.h
	gen_register_macro((gen_Macro) { lit("_GNU_SOURCE"), MT_Expression, });

	// mdesk/mdesk.h
	gen_register_macros(args(
		((gen_Macro) { lit("MD_NodeFlag_AfterFromBefore"),     MT_Expression,  }),
		((gen_Macro) { lit("md_msg_list_push"),                MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_msg_list_pushf"),               MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_string_list_from_token_flags"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_token_chunk_list_push"),        MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_token_array_from_chunk_list"),  MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_each_node"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_node_rec_depth_first_pre"),     MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_node_rec_depth_first_pre_rev"), MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_push_node"),                    MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_string_from_children"),         MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_tokenize_from_text"),           MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_parse_from_text_tokens"),       MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_parse_from_text"),              MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_tree_from_string"),             MT_Expression, MF_Functional }),
		((gen_Macro) { lit("md_debug_string_list_from_tree"),  MT_Expression, MF_Functional })
	));
}
