
namespace std {
	
	__i16 DbConnection::runCommand(const string& nCommand, D2SCommand * nD2SCommand)
	{
		__i16 errorCode_ = 0, rowCount_ = 0;
		__i16 errorCode_ = this->runCommand(nCommand.c_str(), nCommand.length());
		nD2SCommand->setErrorCode(errorCode_);
		if ( DbError_::mSucess_ == errorCode_ ) {
			rowCount_ = static_cast<__i16>(mysql_affected_rows(mHandle));
			nD2SCommand->setRowCount(rowCount_);
		}
		return errorCode_;
	}
	
	__i16 DbConnection::runCommand(const char * nCommand, __i16 nLength)
	{
		int errorCode_ = 0, errorNo_ = 0;
		for (int i = 0; i < 2; ++i) {
			errorCode_ = mysql_real_query(&mHandle, nCommand, nLength);
			if (0 == errorCode_) break;
			if ( i > 0 ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mHandle)));
				return DbError_::mCommand_;
			}
			errorNo_ = mysql_errno(&mHandle);
			if ( (CR_SERVER_GONE_ERROR == errorNo_)
				|| (CR_SERVER_LOST == errorNo_) ) {
				this->runActivate(true);
				continue;
			}
		}
		return DbError_::mSucess_;
	}
	
	__i16 DbConnection::runQuery(const string& nQuery, D2SQuery * nD2SQuery)
	{
		__i16 errorCode_ = 0, rowCount_ = 0;
		__i16 errorCode_ = this->runCommand(nCommand.c_str(), nCommand.length());
		if ( DbError_::mSucess_ != errorCode_ ) {
			nD2SQuery->setErrorCode(errorCode_);
			return errorCode_;
		}
		MYSQL_RES * dbResult_ = mysql_store_result(mHandle);
		if ( nullptr == dbResult_ ) {
			nD2SQuery->setErrorCode(DbError_::mNoResult_);
			return DbError_::mSucess_;
		}
		__i16 rowCount_ = static_cast<__i16>(mysql_num_rows(mHandle));
		if ( rowCount_ <= 0 ) {
			nD2SQuery->setErrorCode(DbError_::mSucess_);
			mysql_free_result(dbResult_);
			return DbError_::mSucess_;
		}
		MYSQL_FIELD * fieldResult_ = mysql_fetch_fields(dbResult_);
        __i16 fieldCount_ = mysql_field_count(mHandle);
		DbResult dbResult_(dbResult_, rowCount_, fieldResult_, fieldCount_);
		dbResult_->runQuery(nD2SQuery);
		return errorCode_;
	}
	
	__i16 DbConnection::runPreCommand(S2DPreCommand * nS2DPreCommand, D2SPreCommand * nD2SPreCommand)
	{
		__i16 command_ = nS2DPreCommand->getCommand();
		auto it = mDbStatements.find(command_);
		if ( it == mDbStatements.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(command_));
			return DbError_::mNoStatement_;
		}
		const list<DbParam>& dbParams_ = nS2DPreCommand->getDbParams();
	}
	
	__i16 DbConnection::runPreQuery(S2DPreQuery * nS2DPreQuery, D2SPreQuery * nD2SPreQuery)
	{
	}
	
	void DbConnection::runRecycle()
	{
		mBusy = false;
	}
	
	bool DbConnection::runAcquire(bool nInit)
	{
		this->runActivate();
		if ( (!mBusy) && mConnected ) {
			mBusy = true;
			return true;
		}
		return false;
	}
	
	__i16 DbConnection::runPreStatement()
	{
		const map<__i32, string>& preCommands_ = mDataBase->getPreCommands();
		for ( auto& it : preCommands_ ) {
			MYSQL_STMT * stmtHandle_ = mysql_stmt_init(mHandle);
			if ( nullptr == stmtHandle_ ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mHandle)));
				return DbError_::StmtInit_;
			}
			if ( 0 != mysql_stmt_prepare(stmtHandle_, it.second, it.second.length()) ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_stmt_error(&stmtHandle_)));
				mysql_stmt_close(stmtHandle_);
				return DbError_::StmtPrep_;
			}
			DbStatementPtr dbStatement_(stmtHandle_);
			mDbStatements[it.first] = dbStatement_;
		}
	}
	
	void DbConnection::runActivate(bool nForce)
	{
		if ( (!mConnected ) || nForce ) {
			this->runDisconnect();
			this->runConnect();
			this->runPreStatement();
			return;
		}
		if (!mBusy) {
			TimeService& timeService_ = Singleton<TimeService>::instance();
			__i64 currentTime_ = timeService_.getLocalTime();
			if (currentTime_ > mTimeStamp) {
				this->runDisconnect();
				this->runConnect();
				this->runPreStatement();
			}
		}
	}
	
	bool DbConnection::runConnect()
	{
		if (mConnected) return true;
		if ( internalConnect() ) {
			TimeService& timeService_ = Singleton<TimeService>::instance();
			mTimeStamp = timeService_.getLocalTime();
			mTimeStamp += mDataBase->getMaxUsedSeconds();
			mConnected = true;
			mBusy = false;
			return true;
		}
		return false;
	}
	
	void DbConnection::runDisconnect()
	{
		if (mConnected) {
			internalDisconnect();
			mConnected = false;
			mBusy = false;
			mTimeStamp = 0;
		}
	}
	
	bool DbConnection::internalConnect()
	{
	    if ( nullptr == mysql_init(&mHandle) ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("mysql_init"));
			return false;
		}
		if ( nullptr == mysql_real_connect(&mHandle,
			mDataBase->getHostName().c_str(),
			mDataBase->getUserName().c_str(),
			mDataBase->getPassword().c_str(),
			mDataBase->getDbName().c_str(),
			mDataBase->getPort(), nullptr, 0) ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(mysql_error(&mHandle)));
			return false;
		}
		mysql_set_character_set(mHandle, "utf8");
		return true;
	}
	
	void DbConnection::internalDisconnect()
	{
		::mysql_close(&mHandle);
	}
	
	DbConnection::DbConnection(IDataBase * nDataBase)
		: mDataBase (nDataBase)
		, mBusy (false)
		, mConnected (false)
		, mTimeStamp (0)
	{
	}
	
	DbConnection::~DbConnection()
	{
		mDataBase = nullptr;
		mConnected = false;
		mTimeStamp = 0;
		mBusy = false;
	}
	
}
