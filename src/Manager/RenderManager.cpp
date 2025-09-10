#include "DarkStar/Manager/RenderManager.h"

namespace DarkStar
{
	 RenderManager::RenderManager()
		: m_Renderer(800, 600, "Test Window")
	{
	}

	void RenderManager::Startup()
	{
		m_Renderer.Init();
	}

	void RenderManager::Run()
	{
		m_Renderer.Render();
	}

	void RenderManager::Shutdown()
	{
	}
}
