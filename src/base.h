/*
 
 src/base.h - common application-wide header, mainly used to provide exceptions
 
 ------------------------------------------------------------------------------
 
 Copyright (c) 2012 - 2014 Ben Golightly <golightly.ben@googlemail.com>

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ------------------------------------------------------------------------------
 
 Define: -DBSE_LINUX/-DBSE_WINDOWS -DBITSPACE=32/64
 Optionally: -DBSE_WINDOWS with -DBSE_GRAPHICAL_EXCEPTIONS
 
 20140718: add PROGRAM_NAME and expanded comments
 20140716: add X4/W3
 
*/

#ifndef BSE_BASE_H
#   define BSE_BASE_H


/* Application-wide ID
 * -------------------
 * This is the name that identifies the program. It is printed in error
 * messages and can be used when printing any --help invocation message.
 */
#   define PROGRAM_NAME "hexgen2014" // GNU coreutil convention
#   define PROG_ID PROGRAM_NAME // legacy bse style (deprecated; use PROGRAM_NAME)


/* Platform specific folder names
 * ------------------------------
 * These are used for naming any folders (e.g. ~/.local/share/PROGRAM_FOLDER)
 * with a platform-specific naming convention (usually uppercase and space
 * separated on Windows, and lowercase-hyphenated on Linux).
 *
 * Also defines the directory separator.
 */
#   if defined(BSE_WINDOWS)
#       define PROGRAM_FOLDER  "Hero Extant 2014 World Generator"
#       define PROG_FOLDER_NAME PROGRAM_FOLDER // deprecated
#       define DIR_SEPARATOR "\\"
#   elif defined(BSE_LINUX)
#       define PROGRAM_FOLDER "hexgen2014"
#       define PROG_FOLDER_NAME PROGRAM_FOLDER
#       define DIR_SEPARATOR "/"
#   else
#       error Please define BSE_WINDOWS or BSE_LINUX
#   endif


/* Bitspace: please compile with -DBSE_BITSPACE=32 or =64
 * ------------------------------------------------------
 * This is not autodetected because it is more robust for the person managing
 * the build system to say what they mean and have the program complain if
 * the environment is not what is expected.
 */
#   if (!defined(BSE_BITSPACE))
#       error Please define BSE_BITSPACE
#   elif (BSE_BITSPACE == 32)
#   elif (BSE_BITSPACE == 64)
#   else
#       error BSE_BITSPACE must be 32 or 64
#   endif


/* Performance-impacting assertions
 * --------------------------------
 * Compile with -DBSE_DEBUG if debugging to turn these on.
 */
#   ifdef BSE_DEBUG
#       include <assert.h>
#       define DEBUG_ASSERT(x) assert(x)
#   else
#       define DEBUG_ASSERT(x)
#   endif


    /* Guess at minimum C spec version feature detection */
#   if defined(__STDC__)
#       define IS_C89

#       if defined(__STDC_VERSION__)
#           define IS_C90

#           if (__STDC_VERSION__ >= 199409L)
#               define IS_C94
#           endif

#           if (__STDC_VERSION__ >= 199901L)
#               define IS_C99
#           endif
#       endif
#   endif


    /* Basic Macros */
#   define UNUSED(x)            ((void)x)
#   define NOP                  ((void)0)

#   define ALIGNMENT_OF(t) \
           offsetof( struct { char anon_x; anon_alignment; }, \
                     anon_alignment)


    /* This isn't always defined. It turns __STRING(PHRASE) into "PHRASE" */
#   ifndef __STRING
#       define __STRING(x) #x
#   endif


    /* convert e.g. __LINE__ to "123" */
#   define STR_HELPER(x) #x
#   define MACRO_EVAL_STR(x) STR_HELPER(x)


    /* __func__, if available, is a actually a special char array -- note
       that this means it cannot be concatinated by the preproccessor like
       string literals! This also means that the pre-C99 version here is of a
       different type, so watch out and only use STRING_FUNC as a standalone
       parameter to printf.
   */
#   ifdef IS_C99
#       define STRING_FUNC  __func__
#   else
#       define STRING_FUNC   "(unknown __func__)"
#   endif


    /* Inlining */
#   ifdef __GNUC__
#       define INLINE       __inline__
#       define FORCE_INLINE __attribute__((always_inline)) __inline__
#   else
#       warning Using default inline keyword (expected GNUC)
#       define INLINE inline
#       define FORCE_INLINE inline
#   endif

#   define HEADER_FUNC static FORCE_INLINE


    /* Llibrary symbol visibility (compile with -fvisibility=hidden) */
#   if (defined(__GNUC__)) && (__GNUC__ >= 4)
#       define public   __attribute__ ((visibility ("default")))
#       define private  __attribute__ ((visibility ("hidden")))
#   else
#       warning Cannot mark attributes as public or private (expected GNUC >= 4)
#       define public
#       define private
#   endif


/* ============================== Exceptions ================================= */

/*
 * Compile with -DBSE_GRAPHICAL_EXCEPTIONS for graphical messageboxes on Windows
 * Compile with -DQUIET_EXCEPTIONS to suppress all error messages
 *
 * X(foo)
 *  -- print an error message, then goto the label err_foo
 *
 * X2(foo, "msg")
 *  -- print an error message and "msg", then goto the label err_foo
 *
 * X3(foo, "msg", int errno)
 *  -- print an error message and "msg" and the errno translated to a string,
 *     then goto the label err_foo
 *
 * X4(foo, "msg", int errno, int detail)
 *  -- print an error message and "msg" and the errno translated to a string
 *     and the detail integer value then goto the label err_foo
 *
 * W("msg")
 *  -- print a warning message and "msg"
 *
 * W2("msg", int errno)
 *  -- print a warning message and "msg" and the errno translated to a string
 *
 * W3("msg", int errno, int detail)
 *  -- print a warning message and "msg" and the errno translated to a string
 *     and the detail integer value
 *
 * I("msg")
 *  -- print an information message "msg"
 *
 * I2("msg", "value desc", int value)
 *  -- print an information message "msg", and the detail integer value with
 *     a given title.
 */

#   ifdef X // error
#       error X already defined
#   endif

#   ifdef X2
#       error X2 already defined
#   endif

#   ifdef X3
#       error X3 already defined
#   endif

#   ifdef X4
#       error X4 already defined
#   endif

#   ifdef W // warning
#       error W already defined
#   endif

#   ifdef W2
#       error W2 already defined
#   endif

#   ifdef W3
#       error W3 already defined
#   endif

#   ifdef I // info
#       error I already defined
#   endif

#   ifdef I2
#       error I2 already defined
#   endif

#   ifndef QUIET_EXCEPTIONS
#       define X(label) \
            X2(label, NULL)

#       define X2(label, msg) \
            bse_print_exception("Exception", __FILE__, __LINE__, STRING_FUNC, __STRING(label), msg, 0, 0); \
            goto err_##label;

#       define X3(label, msg, errnum) \
            bse_print_exception("Exception", __FILE__, __LINE__, STRING_FUNC, __STRING(label), msg, errnum, 0); \
            goto err_##label;

#       define X4(label, msg, errnum, detail) \
            bse_print_exception("Exception", __FILE__, __LINE__, STRING_FUNC, __STRING(label), msg, errnum, (int) (detail)); \
            goto err_##label;

#       define W(msg) \
            bse_print_warning("Warning", __FILE__, __LINE__, STRING_FUNC, msg, 0, 0);

#       define W2(msg, errnum) \
            bse_print_warning("Warning", __FILE__, __LINE__, STRING_FUNC, msg, errnum, 0);

#       define W3(msg, errnum, detail) \
            bse_print_warning("Warning", __FILE__, __LINE__, STRING_FUNC, msg, errnum, (int) (detail));

#       define I(msg) \
            bse_print_info(__FILE__, __LINE__, STRING_FUNC, msg, NULL, 0);

#       define I2(msg, vs, v) \
            bse_print_info(__FILE__, __LINE__, STRING_FUNC, msg, vs, v);

#   else
#       define X(label)                         goto err_##label;
#       define X2(label, msg)                   goto err_##label;
#       define X3(label, msg, errnum)           goto err_##label;
#       define X4(label, msg, errnum, detail)   goto err_##label;
#       define W(msg)                           NOP;
#       define W2(msg, errnum)                  NOP;
#       define W2(msg, errnum, detail)          NOP;
#       define I(msg)                           NOP;
#       define I2(msg)                          NOP;
#endif

void bse_print_exception
(
    const char *type,
    const char *file,
    unsigned int line,
    const char *func,
    const char *label,
    const char *msg,
    int errnum,
    int detail
);

void bse_print_warning
(
    const char *type,
    const char *file,
    unsigned int line,
    const char *func,
    const char *msg,
    int errnum,
    int detail
);

void bse_print_info
(
    const char *file,
    unsigned int line,
    const char *func,
    const char *msg,
    const char *value_title,
    int value
);

extern int bse_quiet_exceptions; // when set to 1, inhibits printing of errors

#endif // BASE_H
