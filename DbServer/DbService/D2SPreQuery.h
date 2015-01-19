#pragma once

namespace std {
	
	class D2SPreQuery
	{
	public:
		void runClear();
		
		D2SPreQuery();
		~D2SPreQuery();
		
	private:
		BufWriter mBufWriter;
		__i32 mCommandNo;
		__i8 mErrorCode;
		__i16 mRowCount;
	};
	typedef shared_ptr<D2SPreQuery> D2SPreQueryPtr;
	
}
