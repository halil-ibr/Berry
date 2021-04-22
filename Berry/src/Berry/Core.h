#pragma once

#ifdef BR_PLATFORM_WINDOWS
	#ifdef BR_BUILD_DLL
		#define BERRY_API __declspec(dllexport)
	#else
		#define BERRY_API __declspec(dllimport)
	#endif
#else
	#error Berry doesn't support your platform!
#endif