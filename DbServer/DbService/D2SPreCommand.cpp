

namespace std {
	
	void D2SPreCommand::setErrorCode(__i8 nErrorCode)
	{
		mErrorCode = nErrorCode;
	}
	
	void D2SPreCommand::setRowCount(__i16 nRowCount)
	{
		mRowCount = nRowCount;
	}

	D2SPreCommand::D2SPreCommand(__i32 nCommandNo)
		: mCommandNo (nCommandNo)
		, mErrorCode (DbError_::mError_)
		, mRowCount (0)
	{
	}
	
	D2SPreCommand::~D2SPreCommand()
	{
		mCommandNo = 0;
		mErrorCode = DbError_::mError_;
		mRowCount = 0;
	}
	
}
