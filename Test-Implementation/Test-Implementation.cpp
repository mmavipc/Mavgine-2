// Test-Implementation.cpp : Defines the entry point for the console application.
//

#include <Core\Core.h>
#include <Core\Engine\Engine.h>

#ifdef _WIN32
#include <Windows.h>
#endif

typedef void*(*GetEnginePtr)();

int main(int argc, char* argv[])
{
	GetEnginePtr pGetEngineFunc;
	#ifdef _WIN32
		HMODULE hCoreDLL = NULL;
		hCoreDLL = LoadLibraryA("Core.dll");
		pGetEngineFunc = (GetEnginePtr)GetProcAddress(hCoreDLL, "GetEngine");
	#endif

	Mavgine2::Engine *pEngine = (Mavgine2::Engine*)pGetEngineFunc();
	pEngine->Initialize("Test Implementation");
	return 0;
}