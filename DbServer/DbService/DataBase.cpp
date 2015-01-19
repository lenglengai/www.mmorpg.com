

namespace std {
	
	__i16 DataBase::runCommand(const string& nCommand, D2SCommand * nD2SCommand)
	{
		DbConnectionPtr& dbConnection_ = this->acquireConnection();
		if (!dbConnection_) {
			return DbError_::mAcquireConnetion_;
		}
		__i16 result_ = dbConnection_->runCommand(nCommand, nD2SCommand);
		this->recycleConnection(dbConnection_);
		return result_;
	}
	
	__i16 DataBase::runQuery(const string& nQuery, D2SQuery * nD2SQuery)
	{
		DbConnectionPtr& dbConnection_ = this->acquireConnection();
		if (!dbConnection_) {
			return DbError_::mAcquireConnetion_;
		}
		__i16 result_ = dbConnection_->runQuery(nQuery, nD2SQuery);
		this->recycleConnection(dbConnection_);
		return result_;
	}
	
	__i16 DataBase::registerStatement(S2DStatementPtr& nS2DStatement, D2SStatement * nD2SStatement)
	{
		map<__i32, string>& preCommands_ = nS2DStatement->getPreCommand();
		for ( auto& it : preCommands_ ) {
			auto it0 = mPreCommands->find(it.first);
			if ( it0 != mPreCommands.end() ) {
				nD2SStatement->setErrorCode(DbError_::mRepeat_);
				return DbError_::mSucess_;
			}
		}
		for ( auto& it : preCommands_ ) {
			mPreCommands[it.first] = it.second;
		}
		nD2SStatement->setErrorCode(Error_::mSucess_);
		return Error_::mSucess_;
	}
	
	__i16 DataBase::runPreCommand(__i32 nCommand, D2SPreCommand * nD2SPreCommand)
	{
		DbConnectionPtr& dbConnection_ = this->acquireConnection();
		if (!dbConnection_) {
			return DbError_::mAcquireConnetion_;
		}
		__i16 result_ = dbConnection_->runPreCommand(nCommand, nD2SPreCommand);
		this->recycleConnection(dbConnection_);
		return result_;
	}
	
	__i16 DataBase::runPreQuery(__i32 nQuery, D2SPreQuery * nD2SPreQuery)
	{
		DbConnectionPtr& dbConnection_ = this->acquireConnection();
		if (!dbConnection_) {
			return DbError_::mAcquireConnetion_;
		}
		__i16 result_ = dbConnection_->runPreQuery(nQuery, nD2SPreQuery);
		this->recycleConnection(dbConnection_);
		return result_;
	}
	
	const map<__i32, string>& DataBase::getPreCommands() const
	{
		return mPreCommands;
	}
	
	void DataBase::runStop()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		for (auto& it : mDbConnections) {
			it->runDisconnect();
		}
	}
	
	void DataBase::runClear()
	{
		mPreCommands.clear();
		
		std::lock_guard<std::mutex> lock_(mMutex);
		mDbConnections.clear();
	}
	
	DataBase::DataBase()
	{
		this->runClear();
	}
	
	DataBase::~DataBase()
	{
		this->runClear();
	}
	
	void DataBase::recycleConnection(DbConnectionPtr& nDbConnection)
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		nDbConnection->runRecycle();
	}
	
	DbConnectionPtr& DataBase::acquireConnection()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		for (auto& it : mDbConnections) {
			if ( it->runAcquire() ) {
				return it;
			}
		}
		__i32 connectionCount_ = static_cast<__i32>(mDbConnections.size());
		if (connectionCount_ >= mMaxConnections) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(connectionCount_));
			return __defaultptr<DbConnection>();
		}
		DbConnectionPtr dbConnection_(new DbConnection(this));
		dbConnection_->runAcquire(true);
		mDbConnections.push_back(dbConnection_);
		return mDbConnections.back();
	}
	
}
