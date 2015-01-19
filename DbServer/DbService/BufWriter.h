#pragma once

#define SQLSIZE 1024
namespace std {
	
	class BufWriter : noncopyable
	{
	public:
		__i16 runInt8(char * nValue, __i16 nLength);
		__i16 runInt16(char * nValue, __i16 nLength);
		__i16 runInt32(char * nValue, __i16 nLength);
		__i16 runInt64(char * nValue, __i16 nLength);
		__i16 runFloat(char * nValue, __i16 nLength);
		__i16 runDouble(char * nValue, __i16 nLength);
		__i16 runString(char * nValue, __i16 nLength);
		__i16 runBlob(char * nValue, __i16 nLength);
		
		template<typename __t>
		__i16 runCopy(__t& nT) {
			if ((mPos + sizeof(__t)) > SQLSIZE) {
				return DbError_::mOverflow_;
			}
			memcpy((mBuffer + mPos), &nT, sizeof(__t));
			mPos += sizeof(__t);
			return DbError_::mSucess_;
		}
		__i16 runCopy(char * nValue, __i16 nLength);
		virtual void runClear();
		
		BufWriter();
		virtual ~BufWriter();
		
	private:
		char mBuffer[SQLSIZE];
		__i16 mPos;
	};
	
}
