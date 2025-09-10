#pragma once

namespace DarkStar
{
	class Manager
	{
	public:
		Manager() = default;
		virtual ~Manager() = default;

		virtual void Startup() = 0;
		virtual void Run() = 0;
		virtual void Shutdown() = 0;
	};
}
