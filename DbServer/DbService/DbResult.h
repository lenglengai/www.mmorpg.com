#pragma once

namespace std {

	class DbResult
	{
	public:
		__i16 runQuery(D2SQueryPtr& nD2SQuery);
		
		DbResult(MYSQL& nHandle);
		~DbResult();
	
	private:
		MYSQL_RES * mResult;
	};
	
}
#endif
