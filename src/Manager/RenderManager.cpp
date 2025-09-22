#include "DarkStar/Manager/RenderManager.h"

#include "DarkStar/Manager/LogManager.h"

namespace DarkStar
{
	CRenderManager::CRenderManager(const unsigned int height, const unsigned int width, const std::string& windowTitle, const std::shared_ptr<CAssetManager>& assetManager)
		: m_Renderer(width, height, windowTitle.c_str(), assetManager), m_AssetManager(assetManager)
	{
	}

	void CRenderManager::Startup()
	{
		DS_CORE_TRACE("Render Manager Startup");
		m_Renderer.Init();
	}

	void CRenderManager::Run()
	{
		m_Renderer.Render();
	}

	void CRenderManager::Shutdown()
	{
		DS_CORE_TRACE("Render Manager Shutdown");
	}
}
