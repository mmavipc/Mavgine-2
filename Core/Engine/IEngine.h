#ifndef IENGINE_H
#define IENGINE_H

namespace Mavgine2
{
	class IEngine
	{
		public:
			virtual void Initialize(const std::string &strGameName, const unsigned int uiTickRate) = 0;
			virtual void EndGame() = 0;

			virtual int LoadPlugin(const std::string &strName) = 0;
			virtual bool UnloadPlugin(const int &id) = 0;
	};
};

#endif