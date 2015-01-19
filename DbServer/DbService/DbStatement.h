#pragma once

namespace std {
	
	class DbStatement
	{
	public:
		DbStatement();
		~DbStatement();
		
	private:
        MYSQL_STMT * mHandle;
        __i16 mParamCount;
        vector<bool> mParamsSet;
        MYSQL_BIND * mParamBind;
	};
	
}
