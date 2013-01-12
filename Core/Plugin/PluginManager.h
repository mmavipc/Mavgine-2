#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H
#ifndef COREDLL
#error You are not supposed to include this H file, EVER.
#endif

#include <Mavgine2\Core\Plugin.h>
#include <vector>

namespace Mavgine2
{
	class PluginManager
	{
		public:
			static PluginManager* GetSingleton();
			int LoadPlugin(const std::string &strName);
			bool UnloadPlugin(const int &id);
			void TickPlugins();

		private:
			PluginManager();
			~PluginManager();

			std::vector<Plugin*> m_vecPlugins;
	};
};

#endif