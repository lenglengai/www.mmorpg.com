#include "../Include.h"

namespace std {
	
	__i32 __stringid(const char * nValue)
	{
		CrcService& crcService_ = Service<CrcService>::instance();
		return crcService_.runName(nValue);
	}
	
}
