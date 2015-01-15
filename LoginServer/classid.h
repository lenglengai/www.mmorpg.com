#pragma once

namespace std {
	
	extern __i32 __stringid(const char * nValue);
	
	template<typename __t>
	__i32 __classid()
	{
		__i32 result_ = 0;
	#ifdef __WINDOW__
		string className_ = typeid(__t).name();
		className_ = className_.substr(6);
		result_ = __stringid(className_.c_str());
	#else
		const char * className_ = typeid(__t).name();
		char * realName_ = abi::__cxa_demangle(className_, 0, 0, 0);
		result_ = __stringid(realName_);
		::free(realName_);
	#endif
		return result_;
	}
	
	template<typename __t>
	__i32 __classinfo(string& nClassName)
	{
		__i32 result_ = 0;
	#ifdef __WINDOW__
		nClassName = typeid(__t).name();
		nClassName = nClassName.substr(6);
		result_ = __stringid(nClassName.c_str());
	#else
		const char * className_ = typeid(__t).name();
		char * realName_ = abi::__cxa_demangle(className_, 0, 0, 0);
		nClassName = realName_;
		result_ = __stringid(realName_);
		::free(realName_);
	#endif
		return result_;
	}
	
}
