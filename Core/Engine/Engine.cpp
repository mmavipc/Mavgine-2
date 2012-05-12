#include "Engine.h"
#ifdef _WIN32
//#include <Windows.h>
#endif

Mavgine2::Engine::Engine() : m_uiTickRate(0)
{
}

Mavgine2::Engine::~Engine()
{
}

void Mavgine2::Engine::Initialize(const std::string &strGameName, const unsigned int uiTickRate)
{
	m_uiTickRate = uiTickRate;
}

void Mavgine2::Engine::EndGame()
{
	delete this;
#ifdef _WIN32
	exit(0);
#endif
}

int Mavgine2::Engine::LoadPlugin(const std::string &strName)
{
	return -1;
};

bool Mavgine2::Engine::UnloadPlugin(const int &id)
{
	return false;
}