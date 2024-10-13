#pragma once

#ifdef WIN32
#include <Windows.h>
#endif // WIN32

#ifdef BUILD_DLL
	#define BIAN_API __declspec(dllexport)
#else
	#define BIAN_API __declspec(dllimport)
#endif // BUILD_DLL

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

#include "Logger.h"
#include "Time.h"
#include "GameSettings.h"