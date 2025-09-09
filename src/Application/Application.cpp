#include "DarkStar/Application/Application.h"

#include "DarkStar/Engine/Engine.h"

namespace DarkStar
{
	void Application::Run()
	{
		DarkStar::Engine Engine;
		Engine.Start();
	}
}
