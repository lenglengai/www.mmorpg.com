

namespace std {
	
	__i16 S2DPtrQuery::handleRun(SessionPtr& nSession)
	{
		__i32 dataBaseId_ = nSession->getDataBaseId();
		DbService& dbService_ = Singleton<DbService>::instance();
		D2SReQuery * d2SReQuery_ = new D2SReQuery(mCommandNo);
		dbService_->runReQuery(dataBaseId_, mCommand, d2SQuery_);
		PacketPtr packet_(d2SQuery_);
		nSession->runSend(packet_);
		return DbError_::mSucess_;
		
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
