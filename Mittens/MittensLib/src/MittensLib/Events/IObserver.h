#pragma once

namespace Mittens
{
	// Observer Interface
	class IObserver
	{
	public:
		virtual ~IObserver();
		virtual void OnEvent() = 0;
	};
}