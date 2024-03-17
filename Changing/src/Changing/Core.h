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

#ifdef HZ_DEBUG
	#define CHNG_ENABLE_ASSERTS
#endif

#ifdef CHNG_ENABLE_ASSERTS
	#define CHNG_ASSERT(x, ...) { if(!(x)) { CHNG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CHNG_CORE_ASSERT(x, ...) { if(!(x)) { CHNG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CHNG_ASSERT(x, ...)
	#define CHNG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CHNG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)