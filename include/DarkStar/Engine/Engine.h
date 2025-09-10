#pragma once

#include "DarkStar/Core.h"

#include <memory>

namespace DarkStar
{
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
		std::unique_ptr<AssetManager> m_AssetManager;
		std::unique_ptr<RenderManager> m_RenderManager;
	};
}
