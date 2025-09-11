#pragma once

#include "DarkStar/Core.h"

namespace DarkStar
{
	class DARKSTAR_API Manager
	{
	public:
		Manager() = default;
		virtual ~Manager() = default;

		virtual void Startup() = 0;
		virtual void Run() = 0;
		virtual void Shutdown() = 0;
	};
}
