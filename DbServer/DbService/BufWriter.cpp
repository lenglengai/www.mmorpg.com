

namespace std {
	
	__i16 BufWriter::pushValue(enum_field_types nType, char * nValue, __i16 nLength)
	{
		switch (nType) {
			case MYSQL_TYPE_TINY:
				return this->runInt8(nValue, nLength);
            case MYSQL_TYPE_SHORT:
				return this->runInt16(nValue, nLength);
            case MYSQL_TYPE_LONG:
				return this->runInt32(nValue, nLength);
			case MYSQL_TYPE_LONGLONG:
				return this->runInt64(nValue, nLength);
			case MYSQL_TYPE_FLOAT:
				return this->runFloat(nValue, nLength);
            case MYSQL_TYPE_DOUBLE:
				return this->runDouble(nValue, nLength);
            case MYSQL_TYPE_STRING:
            case MYSQL_TYPE_VAR_STRING:
				return this->runString(nValue, nLength);
			case MYSQL_TYPE_TINY_BLOB:
			case MYSQL_TYPE_MEDIUM_BLOB:
			case MYSQL_TYPE_LONG_BLOB:
			case MYSQL_TYPE_BLOB:
				return this->runBlob(nValue, nLength);
			default:
				return DbError_::mNoField_;
        }
	}
	
	__i16 BufWriter::runInt8(char * nValue, __i16 nLength)
	{
		__i8 value_ = __convert<char *, __i8>(nValue);
		return this->runCopy(value_);
	}
	
	__i16 BufWriter::runInt16(char * nValue, __i16 nLength)
	{
		__i16 value_ = __convert<char *, __i16>(nValue);
		return this->runCopy(value_);
	}
	
	__i16 BufWriter::runInt32(char * nValue, __i16 nLength)
	{
		__i32 value_ = __convert<char *, __i32>(nValue);
		return this->runCopy(value_);
	}
	
	__i16 BufWriter::runInt64(char * nValue, __i16 nLength)
	{
		__i64 value_ = __convert<char *, __i64>(nValue);
		return this->runCopy(value_);
	}
	
	__i16 BufWriter::runFloat(char * nValue, __i16 nLength)
	{
		float value_ = __convert<char *, float>(nValue);
		return this->runCopy(value_);
	}
	
	__i16 BufWriter::runDouble(char * nValue, __i16 nLength)
	{
		double value_ = __convert<char *, double>(nValue);
		return this->runCopy(value_);
	}
	
	__i16 BufWriter::runString(char * nValue, __i16 nLength)
	{
		return this->runCopy(nValue, nLength);
	}
	
	__i16 BufWriter::runBlob(char * nValue, __i16 nLength)
	{
		return this->runCopy(nValue, nLength);
	}
	
	__i16 BufWriter::runCopy(char * nValue, __i16 nLength)
	{
		__i16 errorCode_ = this->runInt16(nLength);
		if ( DbError_::mSucess_ !=  errorCode_) {
			return errorCode_;
		}
		if ( (mPos + nLength) > SQLSIZE ) {
			return DbError_::mOverflow_;
		}
		memcpy( (mBuffer + mPos), nValue, nLength );
		mPos += nLength;
		return DbError_::mSucess_;
	}
	
	void BufWriter::runClear()
	{
		memset(mBuffer, 0, sizeof(mBuffer));
		mPos = 0;
	}
	
	BufWriter::BufWriter()
	{
		this->runClear();
	}
	
	BufWriter::~BufWriter()
	{
		this->runClear();
	}
	
}
