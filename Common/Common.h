#pragma once

#ifdef APIEXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi
#endif

#if defined(_WIN32) ||  defined(_WIN64)
#define __WINDOW__
#endif

#ifdef __WINDOW__
#define __FUN__ __FUNCTION__
#else
#define __FUN__ __PRETTY_FUNCTION__
#endif

#ifdef __OVERRIDE__
#define OVERRIDE override
#else
#define OVERRIDE
#endif

#ifdef __FINAL__
#define FINAL final
#else
#define FINAL
#endif

typedef char __i8;
typedef short __i16;
typedef long __i32;
typedef long long __i64;

#include <verinc.h>
#include "stdinc.h"
#include "libinc.h"
#include "default.h"
#include "singleton.h"
#include "noncopyable.h"
#include "error_.h"
#include "convert.h"
#include "classid.h"
#include "versionid.h"
