#pragma once

#include "Changing/Core/Base.h"
#include "Changing/Core/Log.h"
#include <filesystem>

#ifdef CHNG_ENABLE_ASSERTS
	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define CHNG_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CHNG##type##ERROR(msg, __VA_ARGS__); CHNG_DEBUGBREAK(); } }
	#define CHNG_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CHNG_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define CHNG_INTERNAL_ASSERT_NO_MSG(type, check) CHNG_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", CHNG_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define CHNG_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define CHNG_INTERNAL_ASSERT_GET_MACRO(...) CHNG_EXPAND_MACRO( CHNG_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CHNG_INTERNAL_ASSERT_WITH_MSG, CHNG_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define CHNG_ASSERT(...) CHNG_EXPAND_MACRO( CHNG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define CHNG_CORE_ASSERT(...) CHNG_EXPAND_MACRO( CHNG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define CHNG_ASSERT(...)
	#define CHNG_CORE_ASSERT(...)
#endif
