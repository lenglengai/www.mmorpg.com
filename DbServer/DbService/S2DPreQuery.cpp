

namespace std {
	
	__i16 S2DPtrQuery::handleRun(SessionPtr& nSession)
	{
		return DbError_::mSucess_;
	}
	
	S2DPtrQuery::S2DPtrQuery()
		: mCommandNo (0)
		, mCommand (0)
	{
	}
	
	S2DPtrQuery::~S2DPtrQuery()
	{
		mCommandNo = 0;
		mCommand = 0;
	}
	
}
