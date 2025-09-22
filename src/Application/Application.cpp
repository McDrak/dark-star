#include "DarkStar/Application/Application.h"

#include "DarkStar/Engine/Engine.h"

#include <iostream>

namespace DarkStar
{
	CApplication::CApplication(const SApplicationConfiguration& configuration)
		: m_Configuration(configuration)
	{
		std::cout << "Application: " << '\n';
		std::cout << "Size: " << configuration.m_Height << " x " << configuration.m_Width << '\n';
		std::cout << "Title: " << configuration.m_Title << '\n';
	}

	void CApplication::Run()
	{
		CEngine engine(m_Configuration);
		engine.Init();
		engine.Run();
		engine.Shutdown();
	}
}
