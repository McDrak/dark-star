#include "DarkStar/Engine.h"

DarkStar::Engine::Engine()
	: m_Renderer{800, 600, "Test"}
{
}

void DarkStar::Engine::Start()
{
	m_Renderer.Init();
	m_Renderer.Render();
}