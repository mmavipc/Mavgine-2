#ifndef IENGINE_H
#define IENGINE_H

#include <string>

namespace Mavgine2
{
	enum EngineStatus
	{
		ES_INIT = 0,
		ES_RUN,
		ES_SHUTDOWN
	};

	class IEngine
	{
		public:
			virtual void Initialize(const std::string &strGameName, const unsigned int uiTickRate) = 0;
			virtual void EndGame() = 0;

			virtual int LoadPlugin(const std::string &strName) = 0;
			virtual bool UnloadPlugin(const int &id) = 0;

			virtual bool ShouldTick() = 0;
			virtual void Tick() = 0;

			virtual double GetEngineTime() = 0;
			virtual double GetRealTime() = 0;

			virtual EngineStatus GetStatus() = 0;
	};
};

#endif