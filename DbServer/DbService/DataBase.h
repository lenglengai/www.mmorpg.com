#pragma once

namespace std {
	
	class DataBase
	{
	public:
		__i16 runCommand(const string& nCommand, D2SCommand * nD2SCommand);
		__i16 runQuery(const string& nQuery, D2SQuery * nD2SQuery);
		__i16 registerStatement(S2DStatementPtr& nS2DStatement, D2SStatement * nD2SStatement);
		__i16 runPreCommand(S2DPreCommand * nS2DPreCommand, D2SPreCommand * nD2SPreCommand);
		__i16 runPreQuery(S2DPreQuery * nS2DPreQuery, D2SPreQuery * nD2SPreQuery);
		const map<__i32, string>& getPreCommands() const;
		
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
