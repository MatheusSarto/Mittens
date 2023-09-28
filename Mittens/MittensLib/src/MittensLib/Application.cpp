#pragma once
#include "mtspch.h"
#include "Application.h"
#include "Events/EventHandler.h"
#include "handlerTest.h"

namespace Mittens
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}
	// Application Loop
	void Application::Run(void)
	{
		OutputDebugStringA("Run Loop\n");
		while (m_Running)
		{
			// Do stuff
			m_Window->OnUpdate();
		}
	}
}
