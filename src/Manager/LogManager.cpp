#include "DarkStar/Manager/LogManager.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DarkStar
{
	std::shared_ptr<spdlog::logger> CLogManager::m_CoreLogger;
	std::shared_ptr<spdlog::logger> CLogManager::m_ClientLogger;

	void CLogManager::Startup()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_CoreLogger = spdlog::stdout_color_mt("DARKSTAR");
		m_CoreLogger->set_level(spdlog::level::trace);
		DS_CORE_TRACE("Core Logger Startup");

		m_ClientLogger = spdlog::stdout_color_mt("APP");
		m_ClientLogger->set_level(spdlog::level::trace);
		DS_CLIENT_TRACE("App Logger Startup");
	}

	void CLogManager::Shutdown()
	{
		DS_CLIENT_TRACE("App Logger Shutdown");
		DS_CORE_TRACE("Core Logger Shutdown");
	}
}