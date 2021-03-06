

namespace std {
	
	__i16 S2DCommand::handleRun(SessionPtr& nSession)
	{
		__i32 dataBaseId_ = nSession->getDataBaseId();
		DbService& dbService_ = Singleton<DbService>::instance();
		D2SCommand * d2SCommand_ = new D2SCommand(mCommandNo);
		dbService_->runCommand(dataBaseId_, mCommand, d2SCommand_);
		PacketPtr packet_(d2SCommand_);
		nSession->runSend(packet_);
		return DbError_::mSucess_;
	}
	
	S2DCommand::S2DCommand()
		: mCommandNo (0)
		, mCommand ("")
	{
	}
	
	S2DCommand::~S2DCommand()
	{
		mCommandNo = 0;
		mCommand = "";
	}
	
}
