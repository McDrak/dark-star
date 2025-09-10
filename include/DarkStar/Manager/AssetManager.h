#pragma once

#include "Manager.h"

namespace DarkStar
{
	class AssetManager : public Manager
	{
	public:
		AssetManager() = default;
		~AssetManager() override = default;

		void Startup() override;
		void Run() override {}
		void Shutdown() override;
	};
}
