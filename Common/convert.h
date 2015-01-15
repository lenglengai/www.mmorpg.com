#pragma once

namespace std {

	enum class ConvertType_
	{
		mCommon_ = 1,
		mBinary_ = 2,
		mText_ = 3,
		mToUtf8_ = 4,
		mFromUtf8_ = 5
	};

	namespace convert_namespace {

		template<typename __t1, typename __t2>
		struct Convert
		{
			__t2 operator () (const __t1& nValue, const ConvertType_ nConvertType) const
			{
				return static_cast<__t1>(nValue);
			}
		};

		template<typename __t2>
		struct Convert<bool, __t2>
		{
			__t2 operator () (const bool nValue, const ConvertType_ nConvertType) const
			{
				return ((true == nValue) ? 1 : 0);
			}
		};

		template<typename __t2>
		struct Convert<char *, __t2>
		{
			__t2 operator () (const char * nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mBinary_ == nConvertType) {
					return ( *((__t2 *)nValue) );
				}
				stringstream stringStream_;
				stringStream_ << nValue;
				__t2 t_;
				stringStream_ >> t_;
				return t_;
			}
		};
		
		template<typename __t2>
		struct Convert<const char *, __t2>
		{
			__t2 operator () (const char * nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mBinary_ == nConvertType) {
					return ( *((__t2 *)nValue) );
				}
				stringstream stringStream_;
				stringStream_ << nValue;
				__t2 t_;
				stringStream_ >> t_;
				return t_;
			}
		};
		
		template<typename __t2>
		struct Convert<string, __t2>
		{
			__t2 operator () (const string& nValue, const ConvertType_ nConvertType) const
			{
				stringstream stringStream_;
				stringStream_ << nValue;
				__t2 t_;
				stringStream_ >> t_;
				return t_;
			}
		};

		template<typename __t1>
		struct Convert<__t1, bool>
		{
			bool operator () (const __t1& nValue, const ConvertType_ nConvertType) const
			{
				return ((1 == nValue) ? true : false);
			}
		};
		
		template<>
		struct Convert<float, bool>
		{
			bool operator () (const float& nValue, const ConvertType_ nConvertType) const
			{
				return ( ( (0.001f > nValue) && (-0.001f < nValue) ) ? true : false);
			}
		};

		template<>
		struct Convert<double, bool>
		{
			bool operator () (const double& nValue, const ConvertType_ nConvertType) const
			{
				return (((0.001 > nValue) && (-0.001 < nValue)) ? true : false);
			}
		};
		
		template<>
		struct Convert<char *, bool>
		{
			bool operator () (const char * nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mBinary_ == nConvertType) {
					__i8 value_ = *((__i8 *)nValue);
					return ((1 == value_) ? true : false);
				} else if (ConvertType_::mText_ == nConvertType) {
					string value_(nValue);
					return (("true" == value_) ? true : false);
				} else {
					string value_(nValue);
					return (("1" == value_) ? true : false);
				}
				return false;
			}
		};
		
		template<>
		struct Convert<const char *, bool>
		{
			bool operator () (const char * nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mBinary_ == nConvertType) {
					__i8 value_ = *((__i8 *)nValue);
					return ((1 == value_) ? true : false);
				} else if (ConvertType_::mText_ == nConvertType) {
					string value_(nValue);
					return (("true" == value_) ? true : false);
				} else {
					string value_(nValue);
					return (("1" == value_) ? true : false);
				}
				return false;
			}
		};

		template<>
		struct Convert<string, bool>
		{
			bool operator () (const string& nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mText_ == nConvertType) {
					string value_(nValue);
					return (("true" == value_) ? true : false);
				} else if (ConvertType_::mCommon_ == nConvertType) {
					string value_(nValue);
					return (("1" == value_) ? true : false);
				} else {
					return false;
				}
				return false;
			}
		};

		template<>
		struct Convert<char *, __i8>
		{
			__i8 operator () (const char * nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mBinary_ == nConvertType) {
					return ( *((__i8 *)nValue) );
				}
				stringstream stringStream_;
				stringStream_ << nValue;
				__i16 t_; stringStream_ >> t_;
				return static_cast<__i8>(t_);
			}
		};

		template<>
		struct Convert<const char *, __i8>
		{
			__i8 operator () (const char * nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mBinary_ == nConvertType) {
					return ( *((__i8 *)nValue) );
				}
				stringstream stringStream_;
				stringStream_ << nValue;
				__i16 t_; stringStream_ >> t_;
				return static_cast<__i8>(t_);
			}
		};
		
		template<>
		struct Convert<string, __i8>
		{
			__i8 operator () (const string& nValue, const ConvertType_ nConvertType) const
			{
				stringstream stringStream_;
				stringStream_ << nValue;
				__i16 t_; stringStream_ >> t_;
				return static_cast<__i8>(t_);
			}
		};
		
		template<typename __t1>
		struct Convert<__t1, string>
		{
			string operator () (const __t1& nValue, const ConvertType_ nConvertType) const
			{
				stringstream stringStream_;
				stringStream_ << nValue;
				string t_;
				stringStream_ >> t_;
				return t_;
			}
		};
		
		template<>
		struct Convert<bool, string>
		{
			string operator () (const bool nValue, const ConvertType_ nConvertType) const
			{
				if (ConvertType_::mText_ == nConvertType) {
					return ((true == nValue) ? "true" : "false");
				}
				return ((true == nValue) ? "1" : "0");
			}
		};
		
		template<>
		struct Convert<__i8, string>
		{
			string operator () (const __i8 nValue, const ConvertType_ nConvertType) const
			{
				__i16 value_ = static_cast<__i16>(nValue);
				stringstream stringStream_;
				stringStream_ << value_;
				string t_; stringStream_ >> t_;
				return t_;
			}
		};
	}

	template<typename __t1, typename __t2>
	__t2 __convert(const __t1 nValue, const ConvertType_ nConvertType = ConvertType_::mCommon_)
	{
		return convert_namespace::Convert<__t1, __t2>()(nValue, nConvertType);
	}

}

