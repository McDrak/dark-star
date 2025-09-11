#pragma once

#include "Manager.h"
#include "DarkStar/Render/Renderer.h"

namespace DarkStar
{
	class DARKSTAR_API RenderManager : public Manager
	{
	public:
		RenderManager();
		~RenderManager() override = default;

		void Startup() override;
		void Run() override;
		void Shutdown() override;

	private:
		Renderer m_Renderer;
	};
}
