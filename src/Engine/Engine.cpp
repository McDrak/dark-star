#include "DarkStar/Engine/Engine.h"

#include "DarkStar/Manager/AssetManager.h"
#include "DarkStar/Manager/LogManager.h"
#include "DarkStar/Manager/RenderManager.h"

namespace DarkStar
{
	Engine::Engine()
		: m_LogManager(nullptr), m_AssetManager(nullptr), m_RenderManager(nullptr)
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::Init()
	{
		m_LogManager = std::make_shared<LogManager>();
		m_LogManager->Startup();
		m_AssetManager = std::make_shared<AssetManager>();
		m_AssetManager->Startup();
		m_RenderManager = std::make_shared<RenderManager>();
		m_RenderManager->Startup();
		m_RenderManager->SetAssetManager(m_AssetManager);
	}

	void Engine::Run()
	{
		m_LogManager->Run();
		m_AssetManager->Run();
		m_RenderManager->Run();
	}

	void Engine::Shutdown()
	{
		m_RenderManager->Shutdown();
		m_AssetManager->Shutdown();
		m_LogManager->Shutdown();
	}
}
