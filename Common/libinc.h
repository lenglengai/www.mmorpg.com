#pragma once

#ifdef __WINDOW__
#pragma warning( push )
#pragma warning( disable : 4819 )
#endif

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;

#ifndef __WINDOW__
#include <cxxabi.h>
#include <malloc.h>
#endif

#ifdef __WINDOW__
#pragma warning( pop )
#endif
