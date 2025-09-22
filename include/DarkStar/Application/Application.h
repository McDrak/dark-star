#pragma once

#include "DarkStar/Core.h"

#include <memory>
#include <string>

namespace DarkStar
{
	struct SApplicationConfiguration
	{
	public:
		std::string m_Title;

		unsigned int m_Height;

		unsigned int m_Width;

		SApplicationConfiguration()
			: m_Height(0), m_Width(0)
		{
		}

		SApplicationConfiguration(const std::string& title, const unsigned int width, const unsigned int height)
			: m_Title(title), m_Height(height), m_Width(width)
		{
		}
	};

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
