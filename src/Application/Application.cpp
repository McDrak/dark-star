#include "DarkStar/Application/Application.h"

#include "DarkStar/Engine/Engine.h"

namespace DarkStar
{
	void Application::Run()
	{
		Engine engine;
		engine.Init();
		engine.Run();
		engine.Shutdown();
	}
}
