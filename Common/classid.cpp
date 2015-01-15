#include "Common.h"
#include "crypt_buf.h"

namespace std {
	
	__i32 hash_string(const char * nKey, __i16 nOffset) const
	{
		__i32 seed1 = 0x7FED7FED;
		__i32 seed2 = 0xEEEEEEEE;
		__i32 ch;
		while (*nKey != 0) {
			ch = toupper(*nKey++, locale());
			seed1 = crypt_buf[nOffset + ch] ^ (seed1 + seed2);
			seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
		}
		return seed1;
	}
	
	__i32 __stringid(const char * nValue)
	{
		return hash_string(nValue, 0x50);
	}
	
}
