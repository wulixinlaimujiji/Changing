#pragma once

#ifdef CHNG_PLATFORM_WINDOWS
	#ifdef CHNG_BUILD_DLL
		#define CHANGING_API __declspec(dllexport)
	#else
		#define CHANGING_API __declspec(dllimport)
	#endif
#else
	#error Changing only supports Windows!
#endif

#define BIT(x) (1 << x)