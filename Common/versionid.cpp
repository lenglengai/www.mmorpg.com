#include "Common.h"

namespace std {
	
	__i16 __versionid()
	{
		return ((VERHIGH << 10) + VERLOW);
	}
	
	__i16 __vercheck(const __i16 nVersion)
	{
		__i32 high = nVersion >> 10;
		__i32 lower = nVersion & 0x3FF;
		if (high != VERHIGH) return Error_::mMustUpdate_;
		if (lower != VERLOW) return Error_::mHaveUpdate_;
		return Error_::mSucess_;
	}
	
}
