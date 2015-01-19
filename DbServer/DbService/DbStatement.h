#pragma once

namespace std {
	
	class DbStatement
	{
	public:
		DbStatement(MYSQL_STMT * nHandle);
		~DbStatement();
		
	private:
        MYSQL_STMT * mHandle;
        MYSQL_BIND * mParamBind;
	};
	
}
