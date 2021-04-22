#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Berry
{
	class BERRY_API Log
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

// Core loggers
#define BR_CORE_TRACE(...)  Berry::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BR_CORE_INFO(...)   Berry::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BR_CORE_WARN(...)   Berry::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BR_CORE_ERROR(...)  Berry::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client loggers
#define BR_TRACE(...)       Berry::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BR_INFO(...)        Berry::Log::GetClientLogger()->info(__VA_ARGS__)
#define BR_WARN(...)        Berry::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BR_ERROR(...)       Berry::Log::GetClientLogger()->error(__VA_ARGS__)
