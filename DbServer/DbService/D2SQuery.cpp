

namespace std {
	
	void D2SQuery::runClear()
	{
		mBufWriter.runClear();
		
		mCommandNo = 0;
		mErrorCode = DbError_::mError_;
		mRowCount = 0;
	}
	
	D2SQuery::D2SQuery()
	{
		this->runClear();
	}
	
	D2SQuery::~D2SQuery()
	{
		this->runClear();
	}
	
}
