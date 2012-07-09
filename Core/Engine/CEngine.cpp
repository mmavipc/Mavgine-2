#include "CEngine.h"

Mavgine2::CEngine::CEngine() : m_uiTickRate(0), m_engineStartClock(clock()),
	m_engineStatus(ES_INIT)
{
}

Mavgine2::CEngine::~CEngine()
{
}

void Mavgine2::CEngine::Initialize(const std::string &strGameName, const unsigned int uiTickRate)
{
	m_uiTickRate = uiTickRate;
	m_engineStatus = ES_RUN;
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

bool Mavgine2::CEngine::ShouldTick()
{
	static double dTickTime = 1.0/double(m_uiTickRate);
	static double dLastTick = 0;

	if(GetEngineTime()-dLastTick > dTickTime)
	{
		return true;
	}

	return false;
}

void Mavgine2::CEngine::Tick()
{
	//Nothing to tick yet
}

double Mavgine2::CEngine::GetEngineTime()
{
	return double(clock() - m_engineStartClock)/double(CLOCKS_PER_SEC);
}

EngineStatus Mavgine2::CEngine::GetStatus()
{
	return m_engineStatus;
}