#pragma once

namespace std {
	
	class DbService
	{
	public:
		__i16 runCommand(__i32 nDataBaseId, const string& nCommand, D2SCommand * nD2SCommand);
		__i16 runQuery(__i32 nDataBaseId, const string& nQuery, D2SQuery * nD2SQuery);
		__i16 registerStatement(__i32 nDataBaseId, S2DStatementPtr& nS2DStatement, D2SStatement * nD2SStatement);
		__i16 runPreCommand(__i32 nDataBaseId, __i32 nCommand, D2SPreCommand * nD2SPreCommand);
		__i16 runPreQuery(__i32 nDataBaseId, __i32 nQuery, D2SPreQuery * nD2SPreQuery);
		
		bool runPreinit();
		void runStop();
		void runClear();
		
		DbService();
		~DbService();
		
	private:
		map<__i32, DataBasePtr> mDataBases;
	};
	
}
