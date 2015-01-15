#include "../Include.h"

namespace std {

	const string& __defaultstr()
	{
		static string value_("");
		return value_;
	}
	
}
