#pragma once

#include "DarkStar/Core.h"
#include "DarkStar/Utils/ConfigurationUtils.h"

#include <memory>

namespace DarkStar
{
	class DARKSTAR_API CApplication
	{
	public:
		explicit CApplication(const SApplicationConfiguration& configuration);

		virtual ~CApplication() = default;

		void Run();

	protected:
		SApplicationConfiguration m_Configuration;
	};

	// To be defined in the Client App
	std::unique_ptr<CApplication> CreateApplication();
}
