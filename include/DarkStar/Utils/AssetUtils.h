#pragma once

#include "DarkStar/Core.h"
#include "DarkStar/Indetifiers.h"

namespace DarkStar
{
	class DARKSTAR_API AssetUtils
	{
	public:
		constexpr static std::string m_FontAssetKey = "fonts";

		constexpr static std::array<std::pair<Identifiers::AssetTypes, std::string>, 3> m_AssetTypeStringMatchArray = {
			{
				{ Identifiers::AssetTypes::Font, "fonts" },
				{ Identifiers::AssetTypes::Sound, "sounds" },
				{ Identifiers::AssetTypes::Texture, "textures" }
			}
		};

		constexpr static std::array<std::pair<Identifiers::Fonts, std::string>, 1> m_FontStringMatchArray = {
			{
				{ Identifiers::Fonts::RobotoRegular, "robotoRegular" }
			}
		};

		constexpr static auto m_FontLoaderFunction = [](sf::Font& loadedAsset, const std::string& filePath)
		{
			return loadedAsset.openFromFile(filePath);
		};
	};
}