// Core.cpp : Defines the exported functions for the DLL application.
//

#include "Core.h"
#include "Engine\CEngine.h"
#include <Static-Shared-Lib\OSAbstraction\OSAbstraction.h>

Mavgine2::CEngine* g_engine = NULL;

void* GetEngine(const std::string &strVersion)
{
	if(strVersion != EXPECTEDENGINEVERSION)
	{
		Mavgine2::GetOSI()->MsgBox("ERROR: Wrong engine version requested", std::string("Expected version: ") + EXPECTEDENGINEVERSION + "\r\nRequested version: " + strVersion, Mavgine2::ERRORMSG);
		exit(-1);
	}
	if(g_engine == NULL)
	{
		g_engine = new Mavgine2::CEngine;
		return g_engine;
	}
	return g_engine;
}