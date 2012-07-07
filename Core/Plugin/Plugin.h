#ifndef PLUGIN_H
#define PLUGIN_H

#include "..\Engine\IEngine.h"

namespace Mavgine2
{
	//Never move things around in this, lest ye break existing plugins
	enum PluginType
	{
		PT_GENERIC = 0
	};

	class Plugin
	{
		public:
			virtual PluginType PluginLoaded() = 0;
			virtual void PluginUnloaded() = 0;
	};

	typedef Plugin* (*PluginInitFunc)(IEngine *pEngine);
};

#endif