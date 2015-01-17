

namespace std {
	
	__i16 DbService::runCommand(__i32 nDataBaseId, const string& nCommand, D2SCommandPtr& nD2SCommand)
	{
		auto it = mDataBases.find(nDataBaseId);
		if ( it == mDataBases.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nDataBaseId));
			return DbError_::mNoFindDb_;
		}
		DataBasePtr& dataBase_ = it->second;
		return dataBase_->runCommand(nCommand, nD2SCommand);
	}
	
	__i16 DbService::runQuery(__i32 nDataBaseId, const string& nQuery, D2SQueryPtr& nD2SQuery)
	{
		auto it = mDataBases.find(nDataBaseId);
		if ( it == mDataBases.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nDataBaseId));
			return DbError_::mNoFindDb_;
		}
		DataBasePtr& dataBase_ = it->second;
		return dataBase_->runQuery(nQuery, nD2SQuery);
	}
	
	__i16 DbService::registerStatement(__i32 nDataBaseId, S2DStatementPtr& nS2DStatement, D2SStatementPtr& nD2SStatement)
	{
		auto it = mDataBases.find(nDataBaseId);
		if ( it == mDataBases.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nDataBaseId));
			return DbError_::mNoFindDb_;
		}
		DataBasePtr& dataBase_ = it->second;
		return dataBase_->registerStatement(nS2DStatement, nD2SStatement);
	}
	
	__i16 DbService::runPreCommand(__i32 nDataBaseId, __i32 nCommand, D2SPreCommandPtr& nD2SPreCommand)
	{
		auto it = mDataBases.find(nDataBaseId);
		if ( it == mDataBases.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nDataBaseId));
			return DbError_::mNoFindDb_;
		}
		DataBasePtr& dataBase_ = it->second;
		return dataBase_->runPreCommand(nCommand, nD2SPreCommand);
	}
	
	__i16 DbService::runPreQuery(__i32 nDataBaseId, __i32 nQuery, D2SPreQueryPtr& nD2SPreQuery)
	{
		auto it = mDataBases.find(nDataBaseId);
		if ( it == mDataBases.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nDataBaseId));
			return DbError_::mNoFindDb_;
		}
		DataBasePtr& dataBase_ = it->second;
		return dataBase_->runPreQuery(nQuery, nD2SPreQuery);
	}
	
	bool DbService::runPreinit()
	{
		this->runClear();
	}
	
	void DbService::runStop()
	{
		auto it = mDataBases.begin();
		for ( ; it != mDataBases.end(); ++it ) {
			DataBasePtr& dataBase_ = it->second;
			dataBase_->runClose();
		}
	}
	
	void DbService::runClear()
	{
		mDataBases.clear();
	}
	
	DbService::DbService()
	{
	}
	
	DbService::~DbService()
	{
	}
	
}
