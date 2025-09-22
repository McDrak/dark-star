#pragma once

#include "DarkStar/Core.h"

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>

namespace DarkStar
{
	template<typename Identifier, typename Asset>
	class DARKSTAR_API CAssetHolder
	{
		using LoaderFunction = std::function<bool(Asset&, const std::string&)>;

	public:
		CAssetHolder() = default;
		virtual ~CAssetHolder() = default;

		void LoadAsset(const Identifier id, const std::string& filePath, LoaderFunction loaderFunction);
		Asset& GetAsset(const Identifier id);

	private:
		std::unordered_map<Identifier, std::unique_ptr<Asset>> m_Assets;
	};

	template <typename Identifier, typename Asset>
	void CAssetHolder<Identifier, Asset>::LoadAsset(const Identifier id, const std::string& filePath, LoaderFunction loaderFunction)
	{
		std::unique_ptr<Asset> assetPtr = std::make_unique<Asset>();
		if (!loaderFunction(*assetPtr, filePath))
		{
			throw std::runtime_error("AssetHolder::LoadAsset failed to load asset " + filePath);
		}

		m_Assets.emplace(id, std::move(assetPtr));
	}

	template <typename Identifier, typename Asset>
	Asset& CAssetHolder<Identifier, Asset>::GetAsset(const Identifier id)
	{
		if (!m_Assets.contains(id))
		{
			throw std::runtime_error("AssetHolder::GetAsset failed to obtain asset");
		}

		return *m_Assets[id];
	}
}