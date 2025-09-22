#pragma once

#include "Manager.h"
#include "AssetManager.h"
#include "DarkStar/Render/Renderer.h"

namespace DarkStar
{
	class DARKSTAR_API CRenderManager : public IManager
	{
	public:
		explicit CRenderManager(const unsigned int height, const unsigned int width, const std::string& windowTitle, const std::shared_ptr<CAssetManager>& assetManager);
		~CRenderManager() override = default;

		void Startup() override;
		void Run() override;
		void Shutdown() override;

	private:
		CRenderer m_Renderer;
		std::weak_ptr<CAssetManager> m_AssetManager;
	};
}
