#pragma once

#include "Manager.h"
#include "spdlog/logger.h"

#include <memory>

namespace DarkStar
{
	class DARKSTAR_API CLogManager : public IManager
	{
	public:
		CLogManager() = default;
		~CLogManager() override {}

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
#define DS_CORE_TRACE(...)	::DarkStar::CLogManager::GetCoreLogger()->trace(__VA_ARGS__)
#define DS_CORE_INFO(...)	::DarkStar::CLogManager::GetCoreLogger()->info(__VA_ARGS__)
#define DS_CORE_WARN(...)	::DarkStar::CLogManager::GetCoreLogger()->warn(__VA_ARGS__)
#define DS_CORE_ERROR(...)	::DarkStar::CLogManager::GetCoreLogger()->error(__VA_ARGS__)
#define DS_CORE_CRITICAL(...)	::DarkStar::CLogManager::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define DS_CLIENT_TRACE(...)	::DarkStar::CLogManager::GetClientLogger()->trace(__VA_ARGS__)
#define DS_CLIENT_INFO(...)	::DarkStar::CLogManager::GetClientLogger()->info(__VA_ARGS__)
#define DS_CLIENT_WARN(...)	::DarkStar::CLogManager::GetClientLogger()->warn(__VA_ARGS__)
#define DS_CLIENT_ERROR(...)	::DarkStar::CLogManager::GetClientLogger()->error(__VA_ARGS__)
#define DS_CLIENT_CRITICAL(...)	::DarkStar::CLogManager::GetClientLogger()->critical(__VA_ARGS__)
