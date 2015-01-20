

namespace std {
	
	__i8 DbParam::getDbType() const
	{
		return mDbType;
	}
	
	void * DbParam::getDbValue() const
	{
		return static_cast<void *>(&(mDbValue.mInt64));
	}
	
	__i16 DbParam::getLength() const
	{
		return mLength;
	}
	
	char * DbParam::getValue() const
	{
		return mValue;
	}
	
	DbParam::DbParam()
	{
		mDbType = DbType_::mBegin_;
		mDbValue.mInt64 = 0;
		mLength = 0;
		mValue = nullptr;
	}
	
	DbParam::~DbParam()
	{
		mDbType = DbType_::mBegin_;
		mDbValue.mInt64 = 0;
		mLength = 0;
		mValue = nullptr;
	}
	
}
