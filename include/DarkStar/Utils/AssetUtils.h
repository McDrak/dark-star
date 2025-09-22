#pragma once

#include "DarkStar/Core.h"
#include "DarkStar/Indetifiers.h"

namespace DarkStar
{
	class DARKSTAR_API CAssetUtils
	{
	public:
		constexpr static std::string m_FontAssetKey = "fonts";

		constexpr static std::array<std::pair<Identifiers::EAssetTypes, std::string>, 3> m_AssetTypeStringMatchArray = {
			{
				{ Identifiers::EAssetTypes::Font, "fonts" },
				{ Identifiers::EAssetTypes::Sound, "sounds" },
				{ Identifiers::EAssetTypes::Texture, "textures" }
			}
		};

		constexpr static std::array<std::pair<Identifiers::EFonts, std::string>, 1> m_FontStringMatchArray = {
			{
				{ Identifiers::EFonts::RobotoRegular, "robotoRegular" }
			}
		};

		constexpr static auto m_FontLoaderFunction = [](sf::Font& loadedAsset, const std::string& filePath) -> bool
		{
			return loadedAsset.openFromFile(filePath);
		};
	};
}