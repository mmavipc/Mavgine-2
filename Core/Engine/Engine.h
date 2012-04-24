#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "..\Core.h"

namespace Mavgine2
{
	class Engine
	{
		friend void* ::GetEngine(const std::string &strVersion);

		public:
			virtual void Initialize(const std::string &strGameName, const unsigned int uiTickRate);
			virtual void EndGame();

		private:
			Engine();
			~Engine();
			unsigned int m_uiTickRate;
	};
};

#endif