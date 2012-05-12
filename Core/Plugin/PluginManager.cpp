#include "PluginManager.h"
#include <Static-Shared-Lib\OSAbstraction\OSAbstraction.h>

Mavgine2::PluginManager *g_pluginMgr = NULL;

Mavgine2::PluginManager* Mavgine2::PluginManager::GetSingleton()
{
	if(g_pluginMgr == NULL)
	{
		g_pluginMgr = new Mavgine2::PluginManager();
	}
	return g_pluginMgr;
}

Mavgine2::PluginManager::PluginManager()
{
}

Mavgine2::PluginManager::~PluginManager()
{
}