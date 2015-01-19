

namespace std {
	
	void D2SPreQuery::runClear()
	{
		mBufWriter.runClear();
		
		mCommandNo = 0;
		mErrorCode = DbError_::mError_;
		mRowCount = 0;
	}
	
	D2SPreQuery::D2SPreQuery()
	{
		this->runClear();
	}
	
	D2SPreQuery::~D2SPreQuery()
	{
		this->runClear();
	}
	
}
