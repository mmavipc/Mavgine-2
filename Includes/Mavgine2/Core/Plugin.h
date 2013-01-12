#ifndef PLUGIN_H
#define PLUGIN_H

#include <Mavgine2\Core\IEngine.h>

namespace Mavgine2
{
	//Never move things around in this, lest ye break existing plugins
	enum PluginType
	{
		PT_ERROR_LOADING = -1,
		PT_GENERIC = 0
	};

	class Plugin
	{
		public:
			virtual PluginType PluginLoaded() = 0;
			virtual void PluginUnloaded() = 0;

			virtual unsigned int GetLock() = 0;
			virtual bool ReleaseLock(const unsigned int &uiLockCode) = 0;

			virtual bool Ticks() = 0;
			virtual void Tick() = 0;
	};

	typedef Plugin* (*PluginInitFunc)(IEngine *pEngine);
};

#endif