#pragma once
#include "mtspch.h"
#include "Application.h"
#include "Events/EventHandler.h"
#include "handlerTest.h"
#include "Events/ApplicationEvent.h"

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
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		std::cout << "\nApplication Event (" << e.GetName() << "), INFO: \n";
	}

	// Application Loop
	void Application::Run(void)
	{
		WindowResizeEvent e(1280, 720);
		std::cout << e.GetName();

		std::cout << "Run Loop\n";
		while (m_Running)
		{
			// Do stuff
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}
