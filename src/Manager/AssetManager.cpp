#include "DarkStar/Manager/AssetManager.h"

#include "DarkStar/Manager/LogManager.h"
#include "DarkStar/Utils/AssetUtils.h"

#include "SFML/Graphics/Font.hpp"

#include "nlohmann/json.hpp"

#include <fstream>

namespace DarkStar
{
	void AssetManager::Startup()
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

	void AssetManager::Shutdown()
	{
		DS_CORE_TRACE("Asset Manager Shutdown");
	}

	void AssetManager::LoadFromFile(const std::string& filePath)
	{
		std::ifstream file(filePath);
		if (!file.is_open())
		{
			throw std::runtime_error("AssetManager::LoadFromFile " + filePath + " could not be opened");
		}

		const nlohmann::json assetTypeData = nlohmann::json::parse(file);

		for (const auto& [assetName, assetFilePath] : assetTypeData[AssetUtils::m_FontAssetKey].items())
		{
			const auto& fontIterator = std::find_if(
				AssetUtils::m_FontStringMatchArray.begin(),
				AssetUtils::m_FontStringMatchArray.end(),
				[assetName](const std::pair<Identifiers::Fonts, std::string>& currentMatch)
			{
				return assetName == currentMatch.second;
			});
			if (fontIterator)
			{
				LoadAsset<Identifiers::Fonts, sf::Font>(fontIterator->first, assetFilePath.get<std::string>(), AssetUtils::m_FontLoaderFunction);
			}
		}
	}
}
