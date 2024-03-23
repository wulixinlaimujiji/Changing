#pragma once

#include <memory>

#include "Changing/Core/PlatformDetection.h"

#ifdef CHNG_DEBUG
	#if defined(CHNG_PLATFORM_WINDOWS)
		#define CHNG_DEBUGBREAK() __debugbreak()
	#elif defined(CHNG_PLATFORM_LINUX)
		#include <signal.h>
		#define CHNG_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define CHNG_ENABLE_ASSERTS
#else
	#define CHNG_DEBUGBREAK()
#endif

#ifdef CHNG_ENABLE_ASSERTS
	#define CHNG_ASSERT(x, ...) { if(!(x)) { CHNG_ERROR("Assertion Failed: {0}", __VA_ARGS__); CHNG_DEBUGBREAK(); } }
	#define CHNG_CORE_ASSERT(x, ...) { if(!(x)) { CHNG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); CHNG_DEBUGBREAK(); } }	
#else
	#define CHNG_ASSERT(x, ...)
	#define CHNG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CHNG_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Changing {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
