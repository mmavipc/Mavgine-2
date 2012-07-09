#include "CEngine.h"

Mavgine2::CEngine::CEngine() : m_uiTickRate(0), m_engineStartClock(clock()),
	m_engineStatus(ES_INIT), m_dLastTick(0), m_dEngineTime(0)
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
	static const double dTickTime = 1.0/double(m_uiTickRate);

	if(GetRealTime()-m_dLastTick > dTickTime)
	{
		return true;
	}

	return false;
}

void Mavgine2::CEngine::Tick()
{
	PluginManager::GetSingleton()->TickPlugins();

	static const double dTickTime = 1.0/double(m_uiTickRate);
	m_dEngineTime += dTickTime;

	m_dLastTick = GetRealTime();
}

double Mavgine2::CEngine::GetEngineTime()
{
	return m_dEngineTime;
}

double Mavgine2::CEngine::GetRealTime()
{
	return double(clock() - m_engineStartClock)/double(CLOCKS_PER_SEC);
}

Mavgine2::EngineStatus Mavgine2::CEngine::GetStatus()
{
	return m_engineStatus;
}