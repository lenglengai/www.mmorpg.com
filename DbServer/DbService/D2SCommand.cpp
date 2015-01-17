#pragma once

namespace std {
	
#ifdef __DBCLIENT__
	__i16 D2SCommand::handleRun(SessionPtr& nSession)
	{
		return NetError_::mSucess_;
	}
#endif

#ifdef __DBSERVER__
	void D2SCommand::setErrorCode(__i8 nErrorCode)
	{
		mErrorCode = nErrorCode;
	}
	
	void D2SCommand::setAffectedRow(__i16 nAffectedRow)
	{
		mAffectedRow = nAffectedRow;
	}
#endif
#ifdef __DBCLIENT__
	__i32 D2SCommand::getCommandNo()
	{
		return mCommandNo;
	}
	
	__i8 D2SCommand::getErrorCode()
	{
		return mErrorCode;
	}
	
	__i16 D2SCommand::getAffectedRow()
	{
		return mAffectedRow;
	}
#endif
	
#ifdef __DBCLIENT__
	D2SCommand::D2SCommand()
		: mCommandNo (0)
		, mErrorCode (DbError_::mError_)
		, mAffectedRow (0)
	{
	}
#endif
	
#ifdef __DBSERVER__
	D2SCommand::D2SCommand(__i32 nCommandNo)
		: mCommandNo (nCommandNo)
		, mErrorCode (DbError_::mError_)
		, mAffectedRow (0)
	{
	}
#endif
	
	D2SCommand::~D2SCommand()
	{
		mCommandNo = 0;
		mErrorCode = DbError_::mError_;
		mAffectedRow = 0;
	}
	
}
