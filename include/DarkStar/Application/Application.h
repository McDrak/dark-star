#pragma once

#include "DarkStar/Core.h"

namespace DarkStar
{
	class DARKSTAR_API Application
	{
		public:
		Application() = default;
		virtual ~Application() = default;

		void Run();
	};

	// To be defined in the Client App
	Application* CreateApplication();
}
