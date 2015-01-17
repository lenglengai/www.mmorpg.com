

namespace std {
	
	__i16 S2DCommand::handleRun(SessionPtr& nSession)
	{
		return NetError_::mSucess_;
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
