/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <corecrt.h>

#ifndef _EH_H_
#define _EH_H_

#ifndef RC_INVOKED

#pragma pack(push,_CRT_PACKING)

#ifndef __cplusplus
#error eh.h is only for C++!
#endif

extern "C++" {
    _VCRT_EXPORT_STD class type_info;
}

typedef void (__cdecl *terminate_function)(void);
typedef void (__cdecl *terminate_handler)(void);
typedef void (__cdecl *unexpected_function)(void);
typedef void (__cdecl *unexpected_handler)(void);

struct _EXCEPTION_POINTERS;
typedef void (__cdecl *_se_translator_function)(unsigned int,struct _EXCEPTION_POINTERS *);

_CRTIMP __declspec(noreturn) void __cdecl terminate(void) throw();
_CRTIMP void __cdecl unexpected(void);
_CRTIMP int __cdecl _is_exception_typeof(const type_info &_Type,struct _EXCEPTION_POINTERS *_ExceptionPtr);
_CRTIMP terminate_function __cdecl set_terminate(terminate_function _NewPtFunc) throw();
extern "C" _CRTIMP terminate_function __cdecl _get_terminate(void);
_CRTIMP unexpected_function __cdecl set_unexpected(unexpected_function _NewPtFunc);
extern "C" _CRTIMP unexpected_function __cdecl _get_unexpected(void);
_CRTIMP _se_translator_function __cdecl _set_se_translator(_se_translator_function _NewPtFunc);
_CRTIMP bool __cdecl __uncaught_exception(void);

#pragma pack(pop)
#endif
#endif /* End _EH_H_ */

