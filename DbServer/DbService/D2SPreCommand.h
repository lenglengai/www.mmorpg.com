#pragma once

namespace std {
	
	class D2SPreCommand
	{
	public:
		void setErrorCode(__i8 nErrorCode);
		void setRowCount(__i16 nRowCount);
		
		D2SPreCommand(__i32 nCommandNo);
		~D2SPreCommand();
		
	private:
		__i32 mCommandNo;
		__i8 mErrorCode;
		__i16 mRowCount;
	};
	typedef shared_ptr<D2SPreCommand> D2SCommandPtr;
	
}
