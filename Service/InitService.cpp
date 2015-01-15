#include "../Include.h"

namespace std {

	bool InitService::runPreinit()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for (; it != mServices.end(); ++it) {
			IService *& service_ = it->second;
			if ( !service_->runPreinit() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->runPreinit() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::loadConfig()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->loadConfig() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->loadConfig() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initDB()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initDB() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->initDB() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initLogDB()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initLogDB() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->initLogDB() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initTB()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initTB() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->initTB() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initLogTB()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initLogTB() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->initLogTB() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::loadBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->loadBegin() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->loadBegin() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::runLoad()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->runLoad() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->runLoad() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::loadEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->loadEnd() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->loadEnd() ) {
				return false;
			}
		}
		return true;
	}
	
	void InitService::runLuaApi()
	{
	#ifdef __EXPLUA__
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runLuaApi();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->runLuaApi();
		}
	#endif
	}
	
	bool InitService::initBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initBegin() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->initBegin() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::runInit()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->runInit() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->runInit() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initEnd() ) {
				return false;
			}
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			if ( !doing_->initEnd() ) {
				return false;
			}
		}
		return true;
	}
	
	void InitService::startBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->startBegin();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->startBegin();
		}
	}
	
	void InitService::runStart()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runStart();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->runStart();
		}
	}
	
	void InitService::startEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->startEnd();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->startEnd();
		}
	}
	
	void InitService::running()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->running();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->running();
		}
	}
	
	void InitService::stopBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->stopBegin();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->stopBegin();
		}
	}
	
	void InitService::runStop()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runStop();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->runStop();
		}
	}
	
	void InitService::stopEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->stopEnd();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->stopEnd();
		}
	}
	
	void InitService::runClear()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runClear();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->runClear();
		}
	}
	
	void InitService::resumeBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->resumeBegin();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->resumeBegin();
		}
	}
	
	void InitService::runResume()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runResume();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->runResume();
		}
	}
	
	void InitService::resumeEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->resumeEnd();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->resumeEnd();
		}
		mPaused = false;
	}
	
	void InitService::pauseBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->pauseBegin();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->pauseBegin();
		}
	}
	
	void InitService::runPause()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runPause();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->runPause();
		}
	}
	
	void InitService::pauseEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->pauseEnd();
		}
		map<__i32, IDoing *>::iterator it0 = mDoings.begin();
		for (; it0 != mDoings.end(); ++it0) {
			IDoing *& doing_ = it0->second;
			doing_->pauseEnd();
		}
		mPaused = true;
	}
	
	InitService::InitService()
		: mPaused (false)
	{
		mServices.clear();
	}

	InitService::~InitService()
	{
		mServices.clear();
		mPaused = false;
	}

}

int main( int argc, char * argv[] )
{
	using namespace std;
	InitService& initService_ = Singleton<InitService>::instance();
	if (!initService_.runPreinit()) {
		return 0;
	}
	
	if ( !initService_.loadConfig() ) {
		return 0;
	}
	
	if ( !initService_.initDB() ) {
		return 0;
	}
	
	if ( !initService_.initLogDB() ) {
		return 0;
	}
	
	if ( !initService_.loadBegin() ) {
		return 0;
	}
	if ( !initService_.runLoad() ) {
		return 0;
	}
	if ( !initService_.loadEnd() ) {
		return 0;
	}
	
	initService_.runLuaApi();
	
	if ( !initService_.initBegin() ) {
		return 0;
	}
	if ( !initService_.runInit() ) {
		return 0;
	}
	if ( !initService_.initEnd() ) {
		return 0;
	}
	
	initService_.startBegin();
	initService_.runStart();
	initService_.startEnd();
	
	initService_.runing();
	
	initService_.stopBegin();
	initService_.runStop();
	initService_.stopEnd();
	
	initService_.runClear();
	
	return 0;
}
