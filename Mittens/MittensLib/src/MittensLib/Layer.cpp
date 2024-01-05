#pragma once
#include "mtspch.h"
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