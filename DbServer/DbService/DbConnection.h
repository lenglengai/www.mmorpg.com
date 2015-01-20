#pragma once

namespace std {
	
	class DbConnection
	{
	public:
		__i16 runCommand(const string& nCommand, D2SCommand * nD2SCommand);
		__i16 runQuery(const string& nQuery, D2SQuery * nD2SQuery);
		__i16 runPreCommand(S2DPreCommand * nS2DPreCommand, D2SPreCommand * nD2SPreCommand);
		__i16 runPreQuery(S2DPreQuery * nS2DPreQuery, D2SPreQuery * nD2SPreQuery);
		
		bool runAcquire(bool nInit = false);
		void runRecycle();
		
		bool runConnect();
		void runDisconnect();
		
	private:
		__i16 runCommand(const char * nCommand, __i16 nLength);
		__i16 runPreCommand(S2DPreCommand * nS2DPreCommand);
		void runActivate(bool nForce = false);
		bool internalConnect();
		void internalDisconnect();
		
	public:
		explicit DbConnection(DataBase * nDataBase);
		~DbConnection();
		
	private:
		map<__i32, DbStatementPtr> mDbStatements;
		DataBase * mDataBase;
		__i32 mTimeStamp;
		bool mConnected;
		bool mBusy;
		
		MYSQL mHandle;
	};
	typedef shared_ptr<DbConnection> DbConnectionPtr;
	
}
