#pragma once

#include "Core.h"

namespace Mittens
{
	class MTS_API EventHandler
	{
	public:
		virtual void OnEvent() = 0;
	};
}