

namespace std {
	
	void D2SCommand::setErrorCode(__i8 nErrorCode)
	{
		mErrorCode = nErrorCode;
	}
	
	void D2SCommand::setRowCount(__i16 nRowCount)
	{
		mRowCount = nRowCount;
	}

	D2SCommand::D2SCommand(__i32 nCommandNo)
		: mCommandNo (nCommandNo)
		, mErrorCode (DbError_::mError_)
		, mRowCount (0)
	{
	}
	
	D2SCommand::~D2SCommand()
	{
		mCommandNo = 0;
		mErrorCode = DbError_::mError_;
		mRowCount = 0;
	}
	
}
