#pragma once
#include "mtspch.h"

#include "MittensLib/Core.h";
#include "MittensLib/Events/Event.h";
#include <string>;
#include "Layer.h";

namespace Mittens
{
	Layer::Layer(const std::string& name)
		: m_LayerName(name)
	{
	}

	Layer::~Layer()
	{
	}

}