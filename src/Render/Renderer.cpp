#include "DarkStar/Render/Renderer.h"

#include "DarkStar/Indetifiers.h"
#include "DarkStar/Manager/AssetManager.h"
#include "DarkStar/Manager/LogManager.h"
#include "SFML/Graphics.hpp"
#include <cstring>
#include <iostream>
#include <optional>

namespace DarkStar
{
	Renderer::Renderer()
		: m_Width(0), m_Height(0), m_WindowName{}
	{
	}

	Renderer::Renderer(const unsigned int width, const unsigned int height, const char windowName[20])
		: m_Width(width), m_Height(height), m_WindowName{}
	{
		strcpy(m_WindowName, windowName);
	}

	void Renderer::Init()
	{
		const sf::Vector2u videoModeSize(m_Width, m_Height);
		m_Window.create(sf::VideoMode(videoModeSize), m_WindowName);
	}

	void Renderer::Render()
	{
		const auto& sharedAssetManager = m_AssetManager.lock();
		if (!sharedAssetManager)
		{
			DS_CORE_CRITICAL("Renderer::Render - Error Loading the Manager");
			return;
		}
		auto& font = sharedAssetManager->GetAsset<Identifiers::Fonts, sf::Font>(Identifiers::Fonts::RobotoRegular);

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
}
