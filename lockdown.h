/* Target file for Lockdown/Power. */
#pragma once

#undef TARGET_LOCKDOWN
#define TARGET_LOCKDOWN 1

#undef LIB_SPEC
#define LIB_SPEC "-lworstc" /* link against C standard library */

/* Specify custom library wcruntime.o directory */
#undef STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/System/Libraries/"

/* LD defaults to 2MB */
#undef LINK_SPEC
#define LINK_SPEC "-z max-page-size=4096 %{shared:-shared} %{static:-static} %{!shared: %{!static: %{rdynamic:-export-dynamic}}}"

/* Files that are linked before user code.
   The %s tells GCC to look for these files in the library directory. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "wcruntime.o%s crti.o%s crtbegin.o%s"

/* Files that are linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
 
/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__lockdown");      \
    builtin_define ("__power");	        \
    builtin_assert ("system=lockdown");   \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");   \
  } while(0);

