#ifndef COREEXPORT_H
#define COREEXPORT_H

#ifdef COREDLL
#ifdef _WIN32
#define COREEXPORT _declspec(dllexport)
#endif

#else
#ifdef _WIN32
#define COREEXPORT _declspec(dllimport)
#endif
#endif

#endif