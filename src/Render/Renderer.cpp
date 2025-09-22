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
	CRenderer::CRenderer()
		: m_Width(0), m_Height(0), m_WindowName{}
	{
	}

	CRenderer::CRenderer(const unsigned int width, const unsigned int height, const char windowName[20], const std::shared_ptr<CAssetManager>& assetManager)
		: m_Width(width), m_Height(height), m_WindowName{}, m_AssetManager(assetManager)
	{
		strcpy(m_WindowName, windowName);
	}

	void CRenderer::Init()
	{
		const sf::Vector2u videoModeSize(m_Width, m_Height);
		m_Window.create(sf::VideoMode(videoModeSize), m_WindowName);
	}

	void CRenderer::Render()
	{
		const auto& sharedAssetManager = m_AssetManager.lock();
		if (!sharedAssetManager)
		{
			DS_CORE_CRITICAL("Renderer::Render - Error Loading the Manager");
			return;
		}
		auto& font = sharedAssetManager->GetAsset<Identifiers::EFonts, sf::Font>(Identifiers::EFonts::RobotoRegular);

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
