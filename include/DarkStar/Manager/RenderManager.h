#pragma once

#include "AssetManager.h"
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

		void SetAssetManager(const std::shared_ptr<AssetManager>& assetManager) { m_AssetManager = assetManager; }

	private:
		Renderer m_Renderer;
		std::weak_ptr<AssetManager> m_AssetManager;
	};
}
