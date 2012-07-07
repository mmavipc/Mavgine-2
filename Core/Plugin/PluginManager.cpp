#include "PluginManager.h"
#include <Static-Shared-Lib\OSAbstraction\OSAbstraction.h>
#include "..\Core.h"

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

int Mavgine2::PluginManager::LoadPlugin(const std::string &strName)
{
	Mavgine2::PluginInitFunc piFunc = (Mavgine2::PluginInitFunc)Mavgine2::GetOSI()->LoadLibAndGetFunc(strName, "PluginInit");
	Mavgine2::Plugin *newPlugin = NULL;

	if(!piFunc)
	{
		return -1;
	}

	newPlugin = piFunc((IEngine*)GetEngine(EXPECTEDENGINEVERSION));
	if(!newPlugin || newPlugin->PluginLoaded() == PT_ERROR_LOADING)
	{
		return -1;
	}

	bool bReachedEnd = false;
	unsigned int uiIndex = 0;
	for(unsigned int i = 0; i < m_vecPlugins.size(); i++)
	{
		if(m_vecPlugins[i] == NULL)
		{
			uiIndex = i;
			bReachedEnd = true;
			break;
		}
	}

	if(bReachedEnd)
	{
		m_vecPlugins[uiIndex] = newPlugin;
		return uiIndex;
	}
	else
	{
		m_vecPlugins.resize(m_vecPlugins.size()+1);
		m_vecPlugins[m_vecPlugins.size()-2] = newPlugin;
		return m_vecPlugins.size()-2;
	}

	return -1;
}