
namespace std {
	
	__i16 DbConnection::runCommand(const string& nCommand, D2SCommandPtr& nD2SCommand)
	{
		__i16 errorCode_ = 0, affectedRow_ = 0;
		__i16 errorCode_ = this->runCommand(nCommand, affectedRow_);
		nD2SCommand->setErrorCode(errorCode_);
		nD2SCommand->setAffectedRow(affectedRow_);
		return errorCode_;
	}
	
	__i16 DbConnection::runCommand(const string& nCommand, __i16& nAffectedRow)
	{
		int errorCode_ = 0, errorNo_ = 0;
		for (int i = 0; i < 2; ++i) {
			errorCode_ = mysql_real_query(&mHandle, nCommand.c_str(), nCommand.length());
			if (0 == errorCode_) break;
			if ( i > 0 ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mHandle)));
				return Error_::mDbError_;
			}
			errorNo_ = mysql_errno(&mHandle);
			if ( (CR_SERVER_GONE_ERROR == errorNo_)
				|| (CR_SERVER_LOST == errorNo_) ) {
				this->runActivate(true);
				continue;
			}
		}
		nAffectedRow = static_cast<__i16>(mysql_affected_rows(mHandle));
		return Error_::mSucess_;
	}
	
	__i16 DbConnection::runQuery(const string& nQuery, D2SQueryPtr& nD2SQuery)
	{
		__i16 errorCode_ = 0, affectedRow_ = 0;
		__i16 errorCode_ = this->runCommand(nCommand, affectedRow_);
		if ( Error_::mSucess_ != errorCode_ ) {
			nD2SQuery->setErrorCode(errorCode_);
			return errorCode_;
		}
		DbResult dbResult_(mHandle);
		dbResult_->runQuery(nD2SQuery);
		return errorCode_;
	}
	
	__i16 DbConnection::runPreCommand(__i32 nCommand, D2SPreCommandPtr& nD2SPreCommand)
	{
	
	}
	
	__i16 DbConnection::runPreQuery(__i32 nQuery, D2SPreQueryPtr& nD2SPreQuery)
	{
	}
	
	void DbConnection::runRecycle()
	{
		mBusy = false;
	}
	
	bool DbConnection::runAcquire()
	{
		this->runActivate();
		if ( (!mBusy) && mConnected ) {
			mBusy = true;
			return true;
		}
		return false;
	}
	
	void DbConnection::runActivate(bool nForce)
	{
		if ( (!mConnected ) || nForce ) {
			this->runDisconnect();
			this->runConnect();
			return;
		}
		if (!mBusy) {
			TimeService& timeService_ = Singleton<TimeService>::instance();
			__i64 currentTime_ = timeService_.getLocalTime();
			if (currentTime_ > mTimeStamp) {
				this->runDisconnect();
				this->runConnect();
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
