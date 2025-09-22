#pragma once

#include "DarkStar/Core.h"

namespace DarkStar
{
	class DARKSTAR_API IManager
	{
	public:
		virtual ~IManager() = default;

		virtual void Startup() = 0;
		virtual void Run() = 0;
		virtual void Shutdown() = 0;
	};
}
