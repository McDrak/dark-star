#pragma once

#include "Manager.h"

#include "DarkStar/Asset/AssetHolder.h"

#include "SFML/Graphics/Font.hpp"

#include <string>
#include <typeindex>

namespace DarkStar
{
	struct SAssetHolderKey
	{
		std::type_index m_IdType;
		std::type_index m_AssetType;

		bool operator==(const SAssetHolderKey& other) const
		{
			return m_IdType == other.m_IdType && m_AssetType == other.m_AssetType;
		}
	};

	struct SAssetHolderKeyHash
	{
		std::size_t operator()(SAssetHolderKey const& key) const noexcept
		{
			return key.m_IdType.hash_code() ^ (key.m_AssetType.hash_code() << 1);
		}
	};

	struct IAssetHolder
	{
		virtual ~IAssetHolder() = default;
	};

	template<typename TIdentifier, typename TAsset>
	struct SAssetHolderWrapper : IAssetHolder
	{
		CAssetHolder<TIdentifier, TAsset> m_Holder;
	};

	class DARKSTAR_API CAssetManager : public IManager
	{
	public:
		CAssetManager() = default;
		~CAssetManager() override = default;

		void Startup() override;
		void Run() override {}
		void Shutdown() override;

		void LoadFromFile(const std::string& filePath);

		template<typename TIdentifier, typename TAsset>
		TAsset& GetAsset(const TIdentifier id);

	private:
		std::unordered_map<SAssetHolderKey, std::unique_ptr<IAssetHolder>, SAssetHolderKeyHash> m_AssetHolders;

		template<typename TIdentifier, typename TAsset, typename TLoaderFunction>
		void LoadAsset(TIdentifier id, const std::string& filePath, TLoaderFunction loaderFunction);

		template<typename TIdentifier, typename TAsset>
		CAssetHolder<TIdentifier, TAsset>& GetHolder();
	};

	template <typename TIdentifier, typename TAsset>
	TAsset& CAssetManager::GetAsset(const TIdentifier id)
	{
		CAssetHolder<TIdentifier, TAsset>& assetHolder = GetHolder<TIdentifier, TAsset>();
		return assetHolder.GetAsset(id);
	}

	template <typename TIdentifier, typename TAsset, typename TLoaderFunction>
	void CAssetManager::LoadAsset(TIdentifier id, const std::string& filePath, TLoaderFunction loaderFunction)
	{
		CAssetHolder<TIdentifier, TAsset>& assetHolder = GetHolder<TIdentifier, TAsset>();
		assetHolder.LoadAsset(id, filePath, loaderFunction);
	}

	template <typename Identifier, typename Asset>
	CAssetHolder<Identifier, Asset>& CAssetManager::GetHolder()
	{
		SAssetHolderKey assetHolderKey = { std::type_index(typeid(Identifier)), std::type_index(typeid(Asset)) };
		const auto holderIterator = m_AssetHolders.find(assetHolderKey);
		if (holderIterator == m_AssetHolders.end())
		{
			auto assetHolderWrapper = std::make_unique<SAssetHolderWrapper<Identifier, Asset>>();
			CAssetHolder<Identifier, Asset>* rawHolderPtr = &assetHolderWrapper->m_Holder;
			m_AssetHolders.emplace(assetHolderKey, std::move(assetHolderWrapper));
			return *rawHolderPtr;
		}

		IAssetHolder* basePtr = holderIterator->second.get();
		auto* foundAssetHolderWrapper = dynamic_cast<SAssetHolderWrapper<Identifier, Asset>*>(basePtr);
		if (!foundAssetHolderWrapper)
		{
			throw std::runtime_error("AssetManager::GetHolder type mismatch");
		}

		return foundAssetHolderWrapper->m_Holder;
	}
}
