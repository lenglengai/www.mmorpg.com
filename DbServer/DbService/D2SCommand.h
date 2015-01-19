#pragma once

namespace std {
	
	class D2SCommand
	{
	public:
		void setErrorCode(__i8 nErrorCode);
		void setRowCount(__i16 nRowCount);
		
		D2SCommand(__i32 nCommandNo);
		~D2SCommand();
		
	private:
		__i32 mCommandNo;
		__i8 mErrorCode;
		__i16 mRowCount;
	};
	typedef shared_ptr<D2SCommand> D2SCommandPtr;
	
}
