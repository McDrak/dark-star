#pragma once

#include "DarkStar/Core.h"

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>

namespace DarkStar
{
	template<typename TIdentifier, typename TAsset>
	class DARKSTAR_API CAssetHolder
	{
		using LoaderFunction = std::function<bool(TAsset&, const std::string&)>;

	public:
		CAssetHolder() = default;
		virtual ~CAssetHolder() = default;

		void LoadAsset(const TIdentifier id, const std::string& filePath, LoaderFunction loaderFunction);
		TAsset& GetAsset(const TIdentifier id);

	private:
		std::unordered_map<TIdentifier, std::unique_ptr<TAsset>> m_Assets;
	};

	template <typename TIdentifier, typename TAsset>
	void CAssetHolder<TIdentifier, TAsset>::LoadAsset(const TIdentifier id, const std::string& filePath, LoaderFunction loaderFunction)
	{
		std::unique_ptr<TAsset> assetPtr = std::make_unique<TAsset>();
		if (!loaderFunction(*assetPtr, filePath))
		{
			throw std::runtime_error("AssetHolder::LoadAsset failed to load asset " + filePath);
		}

		m_Assets.emplace(id, std::move(assetPtr));
	}

	template <typename TIdentifier, typename TAsset>
	TAsset& CAssetHolder<TIdentifier, TAsset>::GetAsset(const TIdentifier id)
	{
		if (!m_Assets.contains(id))
		{
			throw std::runtime_error("AssetHolder::GetAsset failed to obtain asset");
		}

		return *m_Assets[id];
	}
}