#include "../Include.h"

namespace std {

	bool IService::runPreinit()
	{
		return true;
	}
	
	bool IService::loadConfig()
	{
		return true;
	}
	
	bool IService::initDB()
	{
		return true;
	}
	
	bool IService::initLogDB()
	{
		return true;
	}
	
	bool IService::initTB()
	{
		return true;
	}
	
	bool IService::initLogTB()
	{
		return true;
	}
	
	void IService::runLuaApi()
	{
	}
	
	bool IService::loadBegin()
	{
		return true;
	}
	
	bool IService::runLoad()
	{
		return true;
	}
	
	bool IService::loadEnd()
	{
		return true;
	}
	
	bool IService::initBegin()
	{
		return true;
	}
	
	bool IService::runInit()
	{
		return true;
	}
	
	bool IService::initEnd()
	{
		return true;
	}
	
	void IService::startBegin()
	{
	}
	
	void IService::runStart()
	{
	}
	
	void IService::startEnd()
	{
	}
	
	void IService::runing()
	{
	}
	
	void IService::stopBegin()
	{
	}
	
	void IService::runStop()
	{
	}
	
	void IService::stopEnd()
	{
	}
	
	void IService::runClear()
	{
	}
	
	void IService::resumeBegin()
	{
	}
	
	void IService::runResume()
	{
	}
	
	void IService::resumeEnd()
	{
	}
	
	void IService::pauseBegin()
	{
	}
	
	void IService::runPause()
	{
	}
	
	void IService::pauseEnd()
	{
	}
	
	bool IService::inPause() const
	{
		InitService& initService_ = Singleton<InitService>::instance();
		return initService_.inPause();
	}
	
}
