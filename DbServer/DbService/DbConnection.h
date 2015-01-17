#pragma once

namespace std {
	
	class DbConnection
	{
	public:
		__i16 runCommand(const string& nCommand, D2SCommandPtr& nD2SCommand);
		__i16 runQuery(const string& nQuery, D2SQueryPtr& nD2SQuery);
		__i16 runPreCommand(__i32 nCommand, D2SPreCommandPtr& nD2SPreCommand);
		__i16 runPreQuery(__i32 nQuery, D2SPreQueryPtr& nD2SPreQuery);
	
	public:
		explicit DbConnection(DataBase * nDataBase);
		~DbConnection();
		
	private:
		DataBase * mDataBase;
		__i32 mTimeStamp;
		bool mConnected;
		bool mBusy;
		
		MYSQL mHandle;
	};
	typedef shared_ptr<DbConnection> DbConnectionPtr;
	
}
