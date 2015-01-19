#pragma once

namespace std {

	class DbResult : noncopyable
	{
	public:
		__i16 runQuery(D2SQuery * nD2SQuery);
		
		DbResult(MYSQL_RES * nHandle, __i16 nRowCount,
			MYSQL_FIELD * nFieldResult, __i16 nFieldCount);
		~DbResult();
		
	private:
		MYSQL_RES * mHandle;
		__i16 mRowCount;
		MYSQL_FIELD * mFieldResult;
		__i16 mFieldCount;
	};
	
}
#endif
