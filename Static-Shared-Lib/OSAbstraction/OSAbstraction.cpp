#include <Mavgine2\Static-Lib\OSAbstraction.h>

#ifdef _WIN32
#include <Windows.h>
#endif

Mavgine2::OSInterface* g_osi = NULL;

Mavgine2::OSInterface* Mavgine2::GetOSI()
{
	if(!g_osi)
	{
		#ifdef _WIN32
			g_osi = new Mavgine2::WinInterface;
		#endif
	}
	return g_osi;
}

Mavgine2::WinInterface::WinInterface()
{
}
Mavgine2::WinInterface::~WinInterface()
{
}

void Mavgine2::WinInterface::MsgBox(const std::string &strTitle, const std::string &strText, const MsgBoxType &msgType)
{
	switch(msgType)
	{
		case NORMAL:
			MessageBoxA(NULL, strText.c_str(), strTitle.c_str(), MB_OK);
			break;
		case ALERT:
			MessageBoxA(NULL, strText.c_str(), strTitle.c_str(), MB_ICONWARNING);
			break;
		case ERRORMSG:
			MessageBoxA(NULL, strText.c_str(), strTitle.c_str(), MB_ICONERROR);
			break;
	}
}

void* Mavgine2::WinInterface::LoadLibAndGetFunc(std::string strLibName, const char* szFuncName)
{
	strLibName += ".dll";
	const char *szLibName = strLibName.c_str();
	HMODULE hDLL = NULL;
	hDLL = LoadLibraryA(szLibName);
	if(hDLL)
	{
		return GetProcAddress(hDLL, szFuncName);
	}
	else
	{
		return NULL;
	}
}