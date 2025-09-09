#pragma once

#include "DarkStar/Render/Renderer.h"
#include "DarkStar/Core.h"

namespace DarkStar
{
	class DARKSTAR_API Engine
	{
	public:
		Engine();
		~Engine() = default;

		void Start();

	private:
		Renderer m_Renderer;
	};
}
