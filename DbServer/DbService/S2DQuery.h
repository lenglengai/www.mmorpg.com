#pragma once

namespace std {
	
	class S2DQuery
	{
	public:
		__i16 handleRun(SessionPtr& nSession);
		
		S2DQuery();
		~S2DQuery();
		
	private:
		string mCommand;
		__i32 mCommandNo;
	};
	typedef shared_ptr<S2DQuery> S2DQueryPtr;
	
}
