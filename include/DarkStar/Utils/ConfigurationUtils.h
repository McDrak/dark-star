#pragma once

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
}