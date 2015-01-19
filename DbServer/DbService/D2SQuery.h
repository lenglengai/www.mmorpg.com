#pragma once

namespace std {
	
	class D2SQuery
	{
	public:
		void runClear();
		
		D2SQuery();
		~D2SQuery();
		
	private:
		BufWriter mBufWriter;
		__i32 mCommandNo;
		__i8 mErrorCode;
		__i16 mRowCount;
	};
	typedef shared_ptr<D2SQuery> D2SQueryPtr;
	
}
