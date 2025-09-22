#include "DarkStar/Manager/AssetManager.h"

#include "DarkStar/Manager/LogManager.h"
#include "DarkStar/Utils/AssetUtils.h"

#include "SFML/Graphics/Font.hpp"

#include "nlohmann/json.hpp"

#include <fstream>

namespace DarkStar
{
	void CAssetManager::Startup()
	{
		DS_CORE_TRACE("Asset Manager Startup");

		try
		{
			LoadFromFile("assets/assets.json");
		}
		catch (std::exception error)
		{
			DS_CLIENT_CRITICAL(error.what());
		}
	}

	void CAssetManager::Shutdown()
	{
		DS_CORE_TRACE("Asset Manager Shutdown");
	}

	void CAssetManager::LoadFromFile(const std::string& filePath)
	{
		std::ifstream file(filePath);
		if (!file.is_open())
		{
			throw std::runtime_error("AssetManager::LoadFromFile " + filePath + " could not be opened");
		}

		const nlohmann::json assetTypeData = nlohmann::json::parse(file);
		for (const auto& [assetName, assetFilePath] : assetTypeData[CAssetUtils::m_FontAssetKey].items())
		{
			const auto& fontIterator = std::find_if(
				CAssetUtils::m_FontStringMatchArray.begin(),
				CAssetUtils::m_FontStringMatchArray.end(),
				[assetName](const std::pair<Identifiers::EFonts, std::string>& currentMatch)
			{
				return assetName == currentMatch.second;
			});
			if (fontIterator != nullptr)
			{
				LoadAsset<Identifiers::EFonts, sf::Font>(fontIterator->first, assetFilePath.get<std::string>(), CAssetUtils::m_FontLoaderFunction);
				return;
			}

			DS_CORE_ERROR("AssetManager::LoadFromFile couldn't load asset " + assetName);
		}
	}
}
