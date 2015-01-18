
namespace std {
	
	__i16 DbResult::runQuery(D2SQueryPtr& nD2SQuery)
	{
		mResult = mysql_store_result(&mHandle);
		if (nullptr == mResult) {
			if ( 0 != mysql_errno(&mHandle) ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mHandle)));
				return Error_::mDbError_;
			}
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1("mysql_store_result"));
			return Error_::mDbError_;
		}
		int rowCounts_ = mysql_num_rows(mResult);
		if ( rowCounts_ <= 0 ) {
			return Error_::mSucess_;
		}
		int fieldCounts_ = mysql_num_fields(mResult);
		mRowResult = mysql_fetch_row(mResult);
		mLengths = mysql_fetch_lengths(mMYSQL_RES));
		while ( nullptr != mRowResult ) {
		}
		return Error_::mSucess_;
	}
	
	DbResult::DbResult(MYSQL& nHandle)
		: mHandle (nHandle)
		, mResult (nullptr)
	{
	}
	
	MySqlQuery::~MySqlQuery()
	{
		if (nullptr != mResult) {
			mysql_free_result(mResult);
		}
	}
	
}
