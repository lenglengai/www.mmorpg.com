
namespace std {
	
	__i16 DbResult::runQuery(D2SQuery * nD2SQuery)
	{
		unsigned long * length_ = nullptr;
		__i16 errorCode_ = Error_::mSucess_;
		MYSQL_ROW rowResult_ = mysql_fetch_row(mHandle);
		while ( nullptr != rowResult_ ) {
			length_ = mysql_fetch_lengths(mHandle));
			if (nullptr == length_) break;
			for (__i16 i = 0; i < _fieldCount; i++) {
				switch (mFieldResult[i].type) {
					case MYSQL_TYPE_TINY:
						{
							errorCode_ = nD2SQuery->runInt8(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_SHORT:
						{
							errorCode_ = nD2SQuery->runInt16(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_LONG:
						{
							errorCode_ = nD2SQuery->runInt32(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_LONGLONG:
						{
							errorCode_ = nD2SQuery->runInt64(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_FLOAT:
						{
							errorCode_ = nD2SQuery->runFloat(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_DOUBLE:
						{
							errorCode_ = nD2SQuery->runDouble(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_STRING:
					case MYSQL_TYPE_VAR_STRING:
						{
							errorCode_ = nD2SQuery->runString(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					case MYSQL_TYPE_TINY_BLOB:
					case MYSQL_TYPE_MEDIUM_BLOB:
					case MYSQL_TYPE_LONG_BLOB:
					case MYSQL_TYPE_BLOB:
						{
							errorCode_ = nD2SQuery->runBlob(rowResult_[i], length_[i]);
							if (Error_::mSucess_ != errorCode_) {
								return errorCode_;
							}
						}
						break;
					default:
						return DbError_::mNoField_;
				}
			}
		}
		return Error_::mSucess_;
	}
		
	DbResult::DbResult(MYSQL_RES * nHandle, __i16 nRowCount,
		MYSQL_FIELD * nFieldResult, __i16 nFieldCount)
		: mHandle (nHandle)
		, mRowCount (nRowCount)
		, mFieldResult (nFieldResult)
		, mFieldCount (nFieldCount)
	{
	}
	
	DbResult::~DbResult()
	{
		if (nullptr != mHandle) {
			mysql_free_result(mHandle);
		}
	}
	
}
