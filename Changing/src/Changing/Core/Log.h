#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Changing {

	class CHANGING_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CHNG_CORE_TRACE(...) ::Changing::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CHNG_CORE_INFO(...)  ::Changing::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CHNG_CORE_WARN(...)  ::Changing::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CHNG_CORE_ERROR(...) ::Changing::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CHNG_CORE_CRITICAL(...) ::Changing::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define CHNG_TRACE(...)      ::Changing::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CHNG_INFO(...)       ::Changing::Log::GetClientLogger()->info(__VA_ARGS__)
#define CHNG_WARN(...)       ::Changing::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CHNG_ERROR(...)      ::Changing::Log::GetClientLogger()->error(__VA_ARGS__)
#define CHNG_CRITICAL(...)      ::Changing::Log::GetClientLogger()->critical(__VA_ARGS__)
