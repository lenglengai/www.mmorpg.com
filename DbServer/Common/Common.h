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

typedef char __i8;
typedef short __i16;
typedef long __i32;
#ifdef __WINDOW__
typedef __int64 __i64;
#else
typedef long long __i64;
#endif

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <memory>
#include <functional>
#include <mutex>
#include <atomic>
#include <chrono>
#include <thread>
#include <random>
#include <typeinfo>
#include <iostream>
#include <sstream>
