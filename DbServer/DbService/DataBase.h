#pragma once

namespace std {
	
	class DataBase
	{
	public:
		__i16 runCommand(const string& nCommand, D2SCommandPtr& nD2SCommand);
		__i16 runQuery(const string& nQuery, D2SQueryPtr& nD2SQuery);
		__i16 registerStatement(S2DStatementPtr& nS2DStatement, D2SStatementPtr& nD2SStatement);
		__i16 runPreCommand(__i32 nCommand, D2SPreCommandPtr& nD2SPreCommand);
		__i16 runPreQuery(__i32 nQuery, D2SPreQueryPtr& nD2SPreQuery);
		
		void runStop();
		void runClear();
		
		DataBase();
		~DataBase();
		
	private:
		void recycleConnection(DbConnectionPtr& nDbConnection);
		DbConnectionPtr& acquireConnection();
		
	private:
		list<DbConnectionPtr> mDbConnections;
		map<__i32, string> mPreCommands;
		mutex mMutex;
	};
	
}
