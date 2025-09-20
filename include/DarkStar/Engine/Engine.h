#pragma once

#include "DarkStar/Core.h"

#include <memory>

namespace DarkStar
{
	class LogManager;
	class AssetManager;
	class RenderManager;

	class DARKSTAR_API Engine
	{
	public:
		Engine();
		~Engine();

		void Init();
		void Run();
		void Shutdown();

	private:
		std::shared_ptr<LogManager> m_LogManager;
		std::shared_ptr<AssetManager> m_AssetManager;
		std::shared_ptr<RenderManager> m_RenderManager;
	};
}
