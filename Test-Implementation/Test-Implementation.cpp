// Test-Implementation.cpp : Defines the entry point for the console application.
//

#include <Core\Core.h>
#include <Core\Engine\Engine.h>
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

	Mavgine2::Engine *pEngine = (Mavgine2::Engine*)pGetEngineFunc(EXPECTEDENGINEVERSION);
	pEngine->Initialize("Test Implementation", 33);

	Mavgine2::GetOSInterface()->MsgBox("Hello", "World!", Mavgine2::NORMAL);
	Mavgine2::GetOSInterface()->MsgBox("Hello", "World!", Mavgine2::ALERT);
	Mavgine2::GetOSInterface()->MsgBox("Hello", "World!", Mavgine2::ERRORMSG);
	return 0;
}