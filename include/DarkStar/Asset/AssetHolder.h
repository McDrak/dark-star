#pragma once

#include "DarkStar/Core.h"

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>

namespace DarkStar
{
	/**
	 * @brief Generic asset holder that loads and stores assets by identifier.
	 * @tparam TIdentifier  Key type used to index assets (must be hashable and equality comparable).
	 * @tparam TAsset Asset type to manage (must be default-constructible).
	 */
	template<typename TIdentifier, typename TAsset>
	class DARKSTAR_API CAssetHolder
	{
		/// Function that loads an asset instance from a file path into an existing TAsset.
		/// Should return true on success, false on failure.
		using LoaderFunction = std::function<bool(TAsset&, const std::string&)>;

	public:
		CAssetHolder() = default;
		virtual ~CAssetHolder() = default;

		/**
		 * @brief Load an asset and store it under the given identifier.
		 * @param id Identifier used to store the asset.
		 * @param filePath Path to the source file for the asset.
		 * @param loaderFunction Callback that initializes the asset from the file path.
		 * @throws std::runtime_error if the loader function reports failure.
		 */
		void LoadAsset(const TIdentifier id, const std::string& filePath, LoaderFunction loaderFunction);

		/**
		 * @brief Get a mutable reference to an asset by its identifier.
		 * @param id Identifier of the requested asset.
		 * @return TAsset& Reference to the stored asset.
		 * @throws std::runtime_error if no asset exists for the given id.
		 */
		TAsset& GetAsset(const TIdentifier id);

	private:
		/// Storage for assets, owning each asset via unique_ptr to avoid copies and ensure clear ownership.
		std::unordered_map<TIdentifier, std::unique_ptr<TAsset>> m_Assets;
	};

	template <typename TIdentifier, typename TAsset>
	void CAssetHolder<TIdentifier, TAsset>::LoadAsset(const TIdentifier id, const std::string& filePath, LoaderFunction loaderFunction)
	{
		// Create a new asset instance and initialize it via the provided loader.
		std::unique_ptr<TAsset> assetPtr = std::make_unique<TAsset>();
		if (!loaderFunction(*assetPtr, filePath))
		{
			throw std::runtime_error("AssetHolder::LoadAsset failed to load asset " + filePath);
		}

		// Store the loaded asset; if the key already exists, emplace will not overwrite it.
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