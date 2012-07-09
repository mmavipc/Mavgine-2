// Test-Implementation.cpp : Defines the entry point for the console application.
//

#include <Core\Core.h>
#include <Core\Engine\IEngine.h>
#include <Static-Shared-Lib\OSAbstraction\OSAbstraction.h>

#ifdef _WIN32
#include <Windows.h>
#endif

typedef void*(*GetEnginePtr)(const std::string &strVersion);

int main(int argc, char* argv[])
{
	GetEnginePtr pGetEngineFunc;
	#ifdef _WIN32
		HMODULE hCoreDLL = NULL;
		hCoreDLL = LoadLibraryA("Core.dll");
		pGetEngineFunc = (GetEnginePtr)GetProcAddress(hCoreDLL, "GetEngine");
	#endif

	Mavgine2::IEngine *pEngine = (Mavgine2::IEngine*)pGetEngineFunc(EXPECTEDENGINEVERSION);
	pEngine->Initialize("Test Implementation", 33);
	int iDummyPlugin = pEngine->LoadPlugin("Dummy");
	if(iDummyPlugin != -1)
	{
		pEngine->UnloadPlugin(iDummyPlugin);
	}

	Mavgine2::GetOSI()->MsgBox("Hello", "World!", Mavgine2::NORMAL);
	Mavgine2::GetOSI()->MsgBox("Hello", "World!", Mavgine2::ALERT);
	Mavgine2::GetOSI()->MsgBox("Hello", "World!", Mavgine2::ERRORMSG);

	while(pEngine->GetStatus() == Mavgine2::ES_INIT)
	{
	}

	while(pEngine->GetStatus() == Mavgine2::ES_RUN)
	{
		if(pEngine->ShouldTick())
		{
			pEngine->Tick();
		}
	}
	return 0;
}