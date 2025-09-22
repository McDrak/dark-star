#pragma once

#include "DarkStar/Core.h"
#include "DarkStar/Manager/AssetManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace DarkStar
{
	class DARKSTAR_API CRenderer
	{
	public:
		CRenderer();
		CRenderer(const unsigned int width, const unsigned int height, const char windowName[20], const std::shared_ptr<CAssetManager>& assetManager);

		~CRenderer() = default;

		void Init();
		void Render();

	private:
		unsigned int m_Width;
		unsigned int m_Height;
		char m_WindowName[20];
		sf::RenderWindow m_Window;
		std::weak_ptr<CAssetManager> m_AssetManager;
	};
}
