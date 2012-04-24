#include "OSAbstraction.h"

#ifdef _WIN32
#include <Windows.h>
#endif

Mavgine2::OSInterface* g_osi = NULL;

Mavgine2::OSInterface* Mavgine2::GetOSInterface()
{
	if(!g_osi)
	{
		#ifdef _WIN32
			g_osi = new Mavgine2::WinInterface;
		#endif
	}
	return g_osi;
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