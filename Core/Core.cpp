// Core.cpp : Defines the exported functions for the DLL application.
//

#include "Core.h"
#include "Engine\Engine.h"

Mavgine2::Engine* g_engine = NULL;

void* GetEngine()
{
	if(g_engine == NULL)
	{
		g_engine = new Mavgine2::Engine;
		return g_engine;
	}
	return g_engine;
}