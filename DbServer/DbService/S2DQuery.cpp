

namespace std {
	
	__i16 S2DQuery::handleRun(SessionPtr& nSession)
	{
		__i32 dataBaseId_ = nSession->getDataBaseId();
		DbService& dbService_ = Singleton<DbService>::instance();
		D2SQuery * d2SQuery_ = new D2SQuery(mCommandNo);
		dbService_->runQuery(dataBaseId_, mCommand, d2SQuery_);
		PacketPtr packet_(d2SQuery_);
		nSession->runSend(packet_);
		return DbError_::mSucess_;
	}
	
	S2DQuery::S2DQuery()
		: mCommandNo (0)
		, mCommand ("")
	{
	}
	
	S2DQuery::~S2DQuery()
	{
		mCommandNo = 0;
		mCommand = "";
	}
	
}
