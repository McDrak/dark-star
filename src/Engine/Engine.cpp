#include "DarkStar/Engine/Engine.h"

#include "DarkStar/Manager/AssetManager.h"
#include "DarkStar/Manager/LogManager.h"
#include "DarkStar/Manager/RenderManager.h"

namespace DarkStar
{
	CEngine::CEngine(const SApplicationConfiguration& configuration)
		: m_AppConfiguration(configuration), m_LogManager(nullptr), m_AssetManager(nullptr), m_RenderManager(nullptr)
	{
	}

	CEngine::~CEngine()
	{
	}

	void CEngine::Init()
	{
		m_LogManager = std::make_shared<CLogManager>();
		m_LogManager->Startup();
		m_AssetManager = std::make_shared<CAssetManager>();
		m_AssetManager->Startup();
		m_RenderManager = std::make_shared<CRenderManager>(m_AppConfiguration.m_Height, m_AppConfiguration.m_Width, m_AppConfiguration.m_Title, m_AssetManager);
		m_RenderManager->Startup();
	}

	void CEngine::Run()
	{
		m_LogManager->Run();
		m_AssetManager->Run();
		m_RenderManager->Run();
	}

	void CEngine::Shutdown()
	{
		m_RenderManager->Shutdown();
		m_AssetManager->Shutdown();
		m_LogManager->Shutdown();
	}
}
