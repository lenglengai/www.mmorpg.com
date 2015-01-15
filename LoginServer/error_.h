#pragma once

namespace std {

	struct Error_
	{
		static const __i16 mBegin_ = 0;
		static const __i16 mSucess_ = 1;
		static const __i16 mHaveUpdate_ = 2;
		static const __i16 mMustUpdate_ = 3;
		static const __i16 mMaintain_ = 4;
		static const __i16 mError_ = 5;
		static const __i16 mDbError_ = 6;
		static const __i16 mEnd_ = 7;
	};

}
