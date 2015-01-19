#pragma once

namespace std {
	
	class S2DPreCommand
	{
	public:
		__i16 handleRun(SessionPtr& nSession);
		const list<DbParam>& getDbParams() const;
		__i16 getCommand() const;
		
		S2DPreCommand();
		~S2DPreCommand();
		
	private:
		list<DbParam> mDbParams;
		__i16 mCommand;
		__i32 mCommandNo;
	};
	typedef shared_ptr<S2DPreCommand> S2DPreCommandPtr;
	
}
