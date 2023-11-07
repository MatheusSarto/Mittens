#pragma once
#include "mtspch.h"
#include "Events/EventHandler.h"
#include "Core.h"
// DELETE THIS LATER
namespace Mittens
{
	class handler : public EventHandler
	{
	public:
		handler() {}
		virtual void OnEvent() override
		{
			std::cout << "Key Pressed Event Test\n";		}
	};
}
