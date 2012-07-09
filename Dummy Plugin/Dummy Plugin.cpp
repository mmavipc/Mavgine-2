// Dummy Plugin.cpp : Defines the exported functions for the DLL application.
//
//It's up to plugins to make themselves crossplatform
#define WIN32_LAN_AND_MEAN
#include <Windows.h>

#include "..\Core\Plugin\Plugin.h"

class DummyPlugin : public Mavgine2::Plugin
{
	public:
		DummyPlugin(Mavgine2::IEngine *pEngine) : m_pEngine(pEngine), m_bInitSuccess(false), m_uiLockCode(0),
			m_bLocked(false), m_bWaitingForLock(false)
		{
			if(pEngine)
			{
				m_bInitSuccess = true;
			}
		}

		Mavgine2::PluginType PluginLoaded()
		{
			if(m_bInitSuccess)
			{
				return Mavgine2::PT_GENERIC;
			}
			return Mavgine2::PT_ERROR_LOADING;
		}

		void PluginUnloaded()
		{
			while(m_bWaitingForLock)
			{
				Sleep(10);
			}
			delete this;
		}

		unsigned int GetLock()
		{
			while(m_bLocked)
			{
				m_bWaitingForLock = true;
				Sleep(10);
			}
			m_uiLockCode = rand();
			m_bLocked = true;
			m_bWaitingForLock = false;
			return m_uiLockCode;
		}

		bool ReleaseLock(const unsigned int &uiLockCode)
		{
			if(uiLockCode == m_uiLockCode)
			{
				m_bLocked = false;
				return true;
			}
			return false;
		}

		bool Ticks()
		{
			//true if plugin should get ticked false if not.
			return true;
		}

		void Tick()
		{
			//Whee this plugin just ticked
		}

	private:
		Mavgine2::IEngine *m_pEngine;
		bool m_bInitSuccess;

		unsigned int m_uiLockCode;
		bool m_bLocked;
		bool m_bWaitingForLock;
};

DummyPlugin *g_Dummy = NULL;

extern "C" __declspec(dllexport) Mavgine2::Plugin* PluginInit(Mavgine2::IEngine *pEngine)
{
	if(!g_Dummy)
	{
		g_Dummy = new DummyPlugin(pEngine);
	}
	return g_Dummy;
}