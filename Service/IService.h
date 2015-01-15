#pragma once

namespace std {

	class __funapi IService : noncopyable
	{
	public:
		virtual bool runPreinit();
		virtual bool loadConfig();
		virtual bool initDB();
		virtual bool initLogDB();
		virtual bool initTB();
		virtual bool initLogTB();
		
		virtual bool loadBegin();
		virtual bool runLoad();
		virtual bool loadEnd();
		
		virtual void runLuaApi();
		
		virtual bool initBegin();
		virtual bool runInit();
		virtual bool initEnd();
		
		virtual void startBegin();
		virtual void runStart();
		virtual void startEnd();
		
		virtual void runing();
		
		virtual void stopBegin();
		virtual void runStop();
		virtual void stopEnd();
		
		virtual void runClear();
		
		virtual void resumeBegin();
		virtual void runResume();
		virtual void resumeEnd();
		
		virtual void pauseBegin();
		virtual void runPause();
		virtual void pauseEnd();
		
		virtual bool inPause() const;
	};
	
}
