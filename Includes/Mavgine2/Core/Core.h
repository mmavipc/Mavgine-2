#ifndef CORE_H
#define CORE_H

#include "CoreExport.h"
#include <string>

#define EXPECTEDENGINEVERSION "MavgineDev"
//namespace C
extern "C"
{
	COREEXPORT void* GetEngine(const std::string &strVersion);
}

#endif