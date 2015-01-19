

namespace std {
	
	__i16 S2DPreCommand::handleRun(SessionPtr& nSession)
	{
		__i32 dataBaseId_ = nSession->getDataBaseId();
		DbService& dbService_ = Singleton<DbService>::instance();
		D2SReCommand * d2SReCommand_ = new D2SReCommand(mCommandNo);
		dbService_->runReCommand(dataBaseId_, this, d2SReCommand_);
		PacketPtr packet_(d2SReCommand_);
		nSession->runSend(packet_);
		return DbError_::mSucess_;
	}
	
	const list<DbParam>& S2DPreCommand::getDbParams() const
	{
		return mDbParams;
	}
	
	__i16 S2DPreCommand::getCommand() const
	{
		return mCommand;
	}
	
	S2DPreCommand::S2DPreCommand()
		: mCommandNo (0)
		, mCommand (0)
	{
		mDbParams.clear();
	}
	
	S2DPreCommand::~S2DPreCommand()
	{
		mDbParams.clear();
		mCommandNo = 0;
		mCommand = 0;
	}
	
}
