#include "DarkStar/Engine/Engine.h"

#include "DarkStar/Manager/AssetManager.h"
#include "DarkStar/Manager/RenderManager.h"

namespace DarkStar
{
	Engine::Engine()
		: m_AssetManager(nullptr), m_RenderManager(nullptr)
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::Init()
	{
		m_AssetManager = std::make_unique<AssetManager>();
		m_AssetManager->Startup();
		m_RenderManager = std::make_unique<RenderManager>();
		m_RenderManager->Startup();
	}

	void Engine::Run()
	{
		m_AssetManager->Run();
		m_RenderManager->Run();
	}

	void Engine::Shutdown()
	{
		m_RenderManager->Shutdown();
		m_AssetManager->Shutdown();
	}
}
