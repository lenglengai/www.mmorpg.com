

namespace std {
	
	__i16 S2DPreCommand::handleRun(SessionPtr& nSession)
	{
		return DbError_::mSucess_;
	}
	
	S2DPreCommand::S2DPreCommand()
		: mCommandNo (0)
		, mCommand (0)
	{
	}
	
	S2DPreCommand::~S2DPreCommand()
	{
		mCommandNo = 0;
		mCommand = 0;
	}
	
}
