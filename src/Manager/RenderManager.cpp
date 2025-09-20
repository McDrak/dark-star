#include "DarkStar/Manager/RenderManager.h"

#include "DarkStar/Manager/LogManager.h"

namespace DarkStar
{
	 RenderManager::RenderManager()
		: m_Renderer(800, 600, "Test Window")
	{
	}

	void RenderManager::Startup()
	{
	 	DS_CORE_TRACE("Render Manager Startup");
		m_Renderer.Init();
	}

	void RenderManager::Run()
	 {
	 	const auto& sharedAssetManager = m_AssetManager.lock();
	 	if (!sharedAssetManager)
	 	{
	 		DS_CORE_CRITICAL("RenderManager::Startup - Error Loading the Manager");
	 		return;
	 	}
	 	m_Renderer.SetAssetManager(sharedAssetManager);
		m_Renderer.Render();
	}

	void RenderManager::Shutdown()
	{
		DS_CORE_TRACE("Render Manager Shutdown");
	}
}
