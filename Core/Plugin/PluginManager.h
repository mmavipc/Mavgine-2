#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H
#ifndef COREDLL
#error You are not supposed to include this H file, EVER.
#endif

#include "Plugin.h"
#include <vector>

namespace Mavgine2
{
	class PluginManager
	{
		public:
			static PluginManager* GetSingleton();
			int LoadPlugin(const std::string &strName);

		private:
			PluginManager();
			~PluginManager();

			std::vector<Plugin*> m_vecPlugins;
	};
};

#endif