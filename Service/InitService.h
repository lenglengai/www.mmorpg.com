#pragma once

namespace std {

	class __funapi InitService : noncopyable
	{
	public:
		bool runPreinit() OVERRIDE FINAL;
		
		bool loadConfig() OVERRIDE FINAL;
		bool initDB() OVERRIDE FINAL;
		bool initLogDB() OVERRIDE FINAL;
		bool initTB() OVERRIDE FINAL;
		bool initLogTB() OVERRIDE FINAL;
		
		bool loadBegin() OVERRIDE FINAL;
		bool runLoad() OVERRIDE FINAL;
		bool loadEnd() OVERRIDE FINAL;
		
		void runLuaApi() OVERRIDE FINAL;
		
		bool initBegin() OVERRIDE FINAL;
		bool runInit() OVERRIDE FINAL;
		bool initEnd() OVERRIDE FINAL;
		
		void startBegin() OVERRIDE FINAL;
		void runStart() OVERRIDE FINAL;
		void startEnd() OVERRIDE FINAL;
		
		void running() OVERRIDE FINAL;
		
		void stopBegin() OVERRIDE FINAL;
		void runStop() OVERRIDE FINAL;
		void stopEnd() OVERRIDE FINAL;
		
		void runClear() OVERRIDE FINAL;
		
		void resumeBegin() OVERRIDE FINAL;
		void runResume() OVERRIDE FINAL;
		void resumeEnd() OVERRIDE FINAL;
		
		void pauseBegin() OVERRIDE FINAL;
		void runPause() OVERRIDE FINAL;
		void pauseEnd() OVERRIDE FINAL;
		
		InitService();
		~InitService();
		
	private:
		map<__i32, IService *> mServices;
		map<__i32, IDoing *> mDoings;
		atomic<bool> mPaused;
	};

}
