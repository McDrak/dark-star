#ifndef ENGINE_H
#define ENGINE_H

#include "Render/Renderer.h"

namespace DarkStar
{
	class Engine
	{
	public:
		Engine();
		~Engine() = default;

		void Start();

	private:
		Renderer m_Renderer;
	};
}

#endif // ENGINE_H