#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel
{
	class HAZEL_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return _coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return _clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};
}

//Core log macros
#define HZ_CORE_TRACE(...)	Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)	Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HZ_TRACE(...)		Hazel::Log::getClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)		Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)		Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)		Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)		Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)
