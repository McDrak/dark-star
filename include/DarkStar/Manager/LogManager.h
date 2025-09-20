#pragma once

#include "Manager.h"
#include "spdlog/logger.h"

#include <memory>

namespace DarkStar
{
	class DARKSTAR_API LogManager : public Manager
	{
	public:
		LogManager() = default;
		~LogManager() override {}

		void Startup() override;
		void Run() override {}
		void Shutdown() override;

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}

// Core Log Macros
#define DS_CORE_TRACE(...)	::DarkStar::LogManager::GetCoreLogger()->trace(__VA_ARGS__)
#define DS_CORE_INFO(...)	::DarkStar::LogManager::GetCoreLogger()->info(__VA_ARGS__)
#define DS_CORE_WARN(...)	::DarkStar::LogManager::GetCoreLogger()->warn(__VA_ARGS__)
#define DS_CORE_ERROR(...)	::DarkStar::LogManager::GetCoreLogger()->error(__VA_ARGS__)
#define DS_CORE_CRITICAL(...)	::DarkStar::LogManager::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define DS_CLIENT_TRACE(...)	::DarkStar::LogManager::GetClientLogger()->trace(__VA_ARGS__)
#define DS_CLIENT_INFO(...)	::DarkStar::LogManager::GetClientLogger()->info(__VA_ARGS__)
#define DS_CLIENT_WARN(...)	::DarkStar::LogManager::GetClientLogger()->warn(__VA_ARGS__)
#define DS_CLIENT_ERROR(...)	::DarkStar::LogManager::GetClientLogger()->error(__VA_ARGS__)
#define DS_CLIENT_CRITICAL(...)	::DarkStar::LogManager::GetClientLogger()->critical(__VA_ARGS__)
