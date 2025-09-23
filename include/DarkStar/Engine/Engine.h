#pragma once

#include "DarkStar/Core.h"
#include "DarkStar/Utils/ConfigurationUtils.h"

#include <memory>

namespace DarkStar
{
	class CLogManager;
	class CAssetManager;
	class CRenderManager;

	class DARKSTAR_API CEngine
	{
	public:
		explicit CEngine(const SApplicationConfiguration& configuration);
		~CEngine();

		void Init();
		void Run();
		void Shutdown();

		std::shared_ptr<CAssetManager> GetAssetManager() const { return m_AssetManager;}

	private:
		SApplicationConfiguration m_AppConfiguration;
		std::shared_ptr<CLogManager> m_LogManager;
		std::shared_ptr<CAssetManager> m_AssetManager;
		std::shared_ptr<CRenderManager> m_RenderManager;
	};
}
