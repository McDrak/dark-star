#include "DarkStar/Render/Renderer.h"

#include "SFML/Graphics.hpp"
#include <cstring>
#include <iostream>
#include <optional>

DarkStar::Renderer::Renderer()
	: m_Width(0), m_Height(0), m_WindowName{}
{
}

 DarkStar::Renderer::Renderer(const unsigned int width, const unsigned int height, const char windowName[20])
	 : m_Width(width), m_Height(height), m_WindowName{}
{
	strcpy(m_WindowName, windowName);
}

void DarkStar::Renderer::Init()
{
	const sf::Vector2u videoModeSize(m_Width, m_Height);
	m_Window.create(sf::VideoMode(videoModeSize), m_WindowName);
}

void DarkStar::Renderer::Render()
{
	sf::Font font;
	if (!font.openFromFile("../../assets/fonts/Roboto-Regular.ttf"))
	{
		std::cout << "Error loading font" << '\n';
		return;
	}

	sf::Text message(font);
	message.setString("Test");
	message.setCharacterSize(100);
	message.setFillColor(sf::Color::White);

	while (m_Window.isOpen())
	{
		while (const std::optional event = m_Window.pollEvent())
		{
			if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				m_Window.close();
			}
		}

		m_Window.clear();
		m_Window.draw(message);
		m_Window.display();
	}
}

