#pragma once

namespace std {
	
	class S2DPreQuery
	{
	public:
		__i16 handleRun(SessionPtr& nSession);
		
		S2DPreQuery();
		~S2DPreQuery();
		
	private:
		__i32 mCommand;
		__i32 mCommandNo;
	};
	typedef shared_ptr<S2DPreQuery> S2DPreQueryPtr;
	
}
