
namespace std {
	
	__i16 DbConnection::runCommand(const string& nCommand, D2SCommandPtr& nD2SCommand)
	{
		__i16 errorCode_ = 0, affectedRow_ = 0;
		__i16 errorCode_ = this->runCommand(nCommand, affectedRow_);
		nD2SCommand->setErrorCode(errorCode_);
		return errorCode_;
	}
	
	__i16 DbConnection::runCommand(const string& nCommand, __i16 nAffectedRow)
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
		return Error_::mSucess_;
	}
	
	__i16 DbConnection::runQuery(const string& nQuery, D2SQueryPtr& nD2SQuery)
	{
		__i16 errorCode_ = this->runCommand(nCommand);
		if ( Error_::mSucess_ != errorCode_ ) {
			nD2SCommand->setErrorCode(errorCode_);
			return errorCode_;
		}
		DbResult dbResult_(mHandle);
		dbResult_->run
		return errorCode_;
	}
	
	__i16 DbConnection::runPreCommand(__i32 nCommand, D2SPreCommandPtr& nD2SPreCommand)
	{
	
	}
	
	__i16 DbConnection::runPreQuery(__i32 nQuery, D2SPreQueryPtr& nD2SPreQuery)
	{
	}
	
}
