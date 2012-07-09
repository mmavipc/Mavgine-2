#include "CEngine.h"
#ifdef _WIN32
//#include <Windows.h>
#endif

Mavgine2::CEngine::CEngine() : m_uiTickRate(0)
{
}

Mavgine2::CEngine::~CEngine()
{
}

void Mavgine2::CEngine::Initialize(const std::string &strGameName, const unsigned int uiTickRate)
{
	m_uiTickRate = uiTickRate;
}

void Mavgine2::CEngine::EndGame()
{
	delete this;
#ifdef _WIN32
	exit(0);
#endif
}

int Mavgine2::CEngine::LoadPlugin(const std::string &strName)
{
	return PluginManager::GetSingleton()->LoadPlugin(strName);
};

bool Mavgine2::CEngine::UnloadPlugin(const int &id)
{
	return PluginManager::GetSingleton()->UnloadPlugin(id);
}