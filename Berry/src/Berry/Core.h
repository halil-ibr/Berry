#pragma once

#ifdef BR_PLATFORM_WINDOWS
	#ifdef BR_BUILD_DLL
		#define BR_API __declspec(dllexport)
	#else
		#define BR_API __declspec(dllimport)
	#endif
#else
	#error Berry doesn't support your platform!
#endif