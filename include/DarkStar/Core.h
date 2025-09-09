#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define DARKSTAR_PLATFORM_WINDOWS
#elif defined(__APPLE__)
	#define DARKSTAR_PLATFORM_APPLE
#elif defined(__linux__)
	#define DARKSTAR_PLATFORM_LINUX
#endif

#ifdef DARKSTAR_PLATFORM_WINDOWS
	#if defined(DARKSTAR_BUILD_DLL)
		#define DARKSTAR_API __declspec(dllexport)
	#else
		#define DARKSTAR_API __declspec(dllimport)
	#endif
#else
	#define DARKSTAR_API
#endif