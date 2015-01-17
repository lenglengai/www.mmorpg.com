#pragma once

namespace std {
	
	class S2DCommand
	{
	public:
		__i16 handleRun(SessionPtr& nSession);
		
		S2DCommand();
		~S2DCommand();
		
	private:
		string mCommand;
		__i32 mCommandNo;
	};
	typedef shared_ptr<S2DCommand> S2DCommandPtr;
	
}
