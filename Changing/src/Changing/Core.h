#pragma once

#include <memory>

#ifdef CHNG_PLATFORM_WINDOWS
#if CHNG_DYNAMIC_LINK
	#ifdef CHNG_BUILD_DLL
		#define CHANGING_API __declspec(dllexport)
	#else
		#define CHANGING_API __declspec(dllimport)
	#endif
#else
	#define CHANGING_API
#endif
#else
	#error Changing only supports Windows!
#endif

#ifdef CHNG_DEBUG
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

namespace Changing {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}
