#pragma once
#include "mtspch.h"
#include "Application.h"
#include "Events/EventHandler.h"
#include "handlerTest.h"

namespace Mittens
{
	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		OutputDebugStringA("\nPRINT ON EVENT\n");
		OutputDebugStringA(e.GetName());
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
