#pragma once

namespace std {
	
	class D2SCommand
	{
	public:
	#ifdef __DBCLIENT__
		__i16 handleRun(SessionPtr& nSession);
	#endif
	#ifdef __DBSERVER__
		void setErrorCode(__i8 nErrorCode);
		void setAffectedRow(__i16 nAffectedRow);
	#endif
	#ifdef __DBCLIENT__
		__i32 getCommandNo();
		__i8 getErrorCode();
		__i16 getAffectedRow();
	#endif
		
	#ifdef __DBCLIENT__
		D2SCommand();
	#endif
	#ifdef __DBSERVER__
		D2SCommand(__i32 nCommandNo);
	#endif
		~D2SCommand();
		
	private:
		__i32 mCommandNo;
		__i8 mErrorCode;
		__i16 mAffectedRow;
	};
	typedef shared_ptr<D2SCommand> D2SCommandPtr;
	
}
