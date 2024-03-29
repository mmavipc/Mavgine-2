#include "PluginManager.h"
#include <Mavgine2\Static-Lib\OSAbstraction.h>
#include <Mavgine2\Core\Core.h>

Mavgine2::PluginManager* Mavgine2::PluginManager::GetSingleton()
{
	static Mavgine2::PluginManager* pluginMgr = new Mavgine2::PluginManager;
	return pluginMgr;
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
		m_vecPlugins[m_vecPlugins.size()-1] = newPlugin;
		return m_vecPlugins.size()-1;
	}

	return -1;
}

bool Mavgine2::PluginManager::UnloadPlugin(const int &id)
{
	if(m_vecPlugins[id])
	{
		m_vecPlugins[id]->PluginUnloaded();
		m_vecPlugins[id] = NULL;
		return true;
	}
	return false;
}

void Mavgine2::PluginManager::TickPlugins()
{
	for(unsigned int i = 0; i < m_vecPlugins.size(); i++)
	{
		if(m_vecPlugins[i])
		{
			unsigned int uiLockCode = m_vecPlugins[i]->GetLock();
			m_vecPlugins[i]->Tick();
			m_vecPlugins[i]->ReleaseLock(uiLockCode);
		}
	}
}