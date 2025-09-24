#pragma once

#include "Manager.h"

#include "DarkStar/Asset/AssetHolder.h"

#include "SFML/Graphics/Font.hpp"

#include <string>
#include <typeindex>

namespace DarkStar
{
	/**
	 * @brief Composite key identifying a concrete asset holder by its id and asset types.
	 * Used to index different typed CAssetHolder instances in the manager.
	 */
	struct SAssetHolderKey
	{
		/// Concrete id type (e.g., Identifiers::EFonts) used by the holder.
		std::type_index m_IdType;
		/// Concrete asset type (e.g., sf::Font) managed by the holder.
		std::type_index m_AssetType;

		/// Equality compares both type components.
		bool operator==(const SAssetHolderKey& other) const
		{
			return m_IdType == other.m_IdType && m_AssetType == other.m_AssetType;
		}
	};

	/**
	 * @brief Hash functor for SAssetHolderKey.
	 * Combines hashes of the two type_index fields.
	 */
	struct SAssetHolderKeyHash
	{
		std::size_t operator()(SAssetHolderKey const& key) const noexcept
		{
			return key.m_IdType.hash_code() ^ (key.m_AssetType.hash_code() << 1);
		}
	};

	/**
	 * @brief Non-templated base to allow type-erased storage of asset holders.
	 */
	struct IAssetHolder
	{
		virtual ~IAssetHolder() = default;
	};

	/**
	 * @brief Type-erased wrapper that embeds a concrete CAssetHolder.
	 * @tparam TIdentifier Identifier enum/type used to look up assets.
	 * @tparam TAsset Concrete asset type managed.
	 */
	template<typename TIdentifier, typename TAsset>
	struct SAssetHolderWrapper : IAssetHolder
	{
		CAssetHolder<TIdentifier, TAsset> m_Holder;
	};

	/**
	 * @brief Manager for loading and retrieving typed assets.
	 * Stores multiple CAssetHolder instances keyed by (Identifier type, Asset type),
	 * enabling heterogeneous asset management behind a single interface.
	 */
	class DARKSTAR_API CAssetManager : public IManager
	{
	public:
		CAssetManager() = default;
		~CAssetManager() override = default;

		/**
		 * @brief Initialize the asset system and load default assets.
		 * Errors are logged; severe failures may be reported via exceptions internally.
		 */
		void Startup() override;

		/// No-op tick for this manager.
		void Run() override {}

		/**
		 * @brief Shutdown hook for the asset system.
		 * Performs any required cleanup/logging.
		 */
		void Shutdown() override;

		/**
		 * @brief Load assets described in a configuration file.
		 * @param filePath Path to a JSON configuration.
		 * @throws std::runtime_error on file/parse/load issues.
		 */
		void LoadFromFile(const std::string& filePath);

		/**
		 * @brief Retrieve a loaded asset by id.
		 * @tparam TIdentifier Identifier enum/type for the asset class.
		 * @tparam TAsset Expected asset type.
		 * @param id Asset identifier value.
		 * @return TAsset& Reference to the stored asset.
		 * @throws std::runtime_error if the asset or holder is missing.
		 */
		template<typename TIdentifier, typename TAsset>
		TAsset& GetAsset(const TIdentifier id);

	private:
		/// Heterogeneous map of typed asset holders, keyed by their (id type, asset type).
		std::unordered_map<SAssetHolderKey, std::unique_ptr<IAssetHolder>, SAssetHolderKeyHash> m_AssetHolders;

		/**
		 * @brief Load a single asset into the appropriate typed holder.
		 * @tparam TIdentifier Identifier enum/type.
		 * @tparam TAsset Asset type.
		 * @tparam TLoaderFunction Callable with signature bool(TAsset&, const std::string&).
		 * @param id Identifier value.
		 * @param filePath Source file for the asset.
		 * @param loaderFunction Loader used to construct/initialize the asset.
		 * @throws std::runtime_error on loading errors.
		 */
		template<typename TIdentifier, typename TAsset, typename TLoaderFunction>
		void LoadAsset(TIdentifier id, const std::string& filePath, TLoaderFunction loaderFunction);

		/**
		 * @brief Obtain (and lazily create if needed) the typed asset holder.
		 * @tparam TIdentifier Identifier type.
		 * @tparam TAsset Asset type.
		 * @return CAssetHolder<TIdentifier, TAsset>& Reference to the typed holder.
		 * @throws std::runtime_error if a stored holder exists with mismatched type.
		 */
		template<typename TIdentifier, typename TAsset>
		CAssetHolder<TIdentifier, TAsset>& GetHolder();
	};

	template <typename TIdentifier, typename TAsset>
	TAsset& CAssetManager::GetAsset(const TIdentifier id)
	{
		// Route to the correct typed holder and retrieve the asset.
		CAssetHolder<TIdentifier, TAsset>& assetHolder = GetHolder<TIdentifier, TAsset>();
		return assetHolder.GetAsset(id);
	}

	template <typename TIdentifier, typename TAsset, typename TLoaderFunction>
	void CAssetManager::LoadAsset(TIdentifier id, const std::string& filePath, TLoaderFunction loaderFunction)
	{
		// Delegate loading to the typed holder, using the provided loader callback.
		CAssetHolder<TIdentifier, TAsset>& assetHolder = GetHolder<TIdentifier, TAsset>();
		assetHolder.LoadAsset(id, filePath, loaderFunction);
	}

	template <typename Identifier, typename Asset>
	CAssetHolder<Identifier, Asset>& CAssetManager::GetHolder()
	{
		// Compose a key from the type parameters and look up an existing holder.
		SAssetHolderKey assetHolderKey = { std::type_index(typeid(Identifier)), std::type_index(typeid(Asset)) };
		const auto holderIterator = m_AssetHolders.find(assetHolderKey);
		if (holderIterator == m_AssetHolders.end())
		{
			// Lazily create and store a new holder wrapper for this type pair.
			auto assetHolderWrapper = std::make_unique<SAssetHolderWrapper<Identifier, Asset>>();
			CAssetHolder<Identifier, Asset>* rawHolderPtr = &assetHolderWrapper->m_Holder;
			m_AssetHolders.emplace(assetHolderKey, std::move(assetHolderWrapper));
			return *rawHolderPtr;
		}

		// Recover the concrete wrapper via dynamic_cast and return its holder.
		IAssetHolder* basePtr = holderIterator->second.get();
		auto* foundAssetHolderWrapper = dynamic_cast<SAssetHolderWrapper<Identifier, Asset>*>(basePtr);
		if (!foundAssetHolderWrapper)
		{
			throw std::runtime_error("AssetManager::GetHolder type mismatch");
		}

		return foundAssetHolderWrapper->m_Holder;
	}
}
