#pragma once

#define SQLSIZE 1024
namespace std {
	
	struct DbType_
	{
		static const __i8 mBegin_ = 0;
		static const __i8 mBool_ = 1;
		static const __i8 mInt8_ = 2;
		static const __i8 mInt16_ = 3;
		static const __i8 mInt32_ = 4;
		static const __i8 mInt64_ = 5;
		static const __i8 mFloat_ = 6;
		static const __i8 mDouble_ = 7;
		static const __i8 mString_ = 8;
		static const __i8 mVarString_ = 9;
		static const __i8 mTinyBlob_ = 10;
		static const __i8 mBlob_ = 11;
		static const __i8 mBigBlob_ = 12;
		static const __i8 mMaxBlob_ = 13;
		static const __i8 mEnd_ = 14;
	};
	
	union DbValue
	{
		bool mBool;
		__i8 mInt8;
		__i16 mInt16;
		__i32 mInt32;
		__i64 mInt64;
		float mFloat;
		double mDouble;
	};
	
	class DbParam : noncopyable
	{
	public:
		
		__i8 getDbType() const;
		void * getDbValue() const;
		__i16 getLength() const;
		char * getValue() const;
		
		DbParam();
		~DbParam();
		
	private:
		__i8 mDbType;
		DbValue mDbValue;
		__i16 mLength;
		char * mValue;
	};
	
}
