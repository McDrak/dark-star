#pragma once

#include "DarkStar/Core.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace DarkStar
{
	class DARKSTAR_API Renderer
	{
	public:
		Renderer();
		Renderer(const unsigned int width, const unsigned int height, const char windowName[20]);

		~Renderer() = default;

		void Init();
		void Render();

	private:
		unsigned int m_Width;
		unsigned int m_Height;
		char m_WindowName[20];
		sf::RenderWindow m_Window;
	};
}
