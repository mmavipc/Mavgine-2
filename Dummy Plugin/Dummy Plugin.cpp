// Dummy Plugin.cpp : Defines the exported functions for the DLL application.
//

#include "..\Core\Plugin\Plugin.h"

class DummyPlugin : public Mavgine2::Plugin
{
	public:
		DummyPlugin(Mavgine2::IEngine *pEngine) : m_pEngine(pEngine), m_bInitSuccess(false)
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
			delete this;
		}

	private:
		Mavgine2::IEngine *m_pEngine;
		bool m_bInitSuccess;
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