#pragma once
#include "Mittens.h"
#include "mtspch.h"
#include "Application.h"

#include <GLAD/glad.h>

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
		std::cout << "\nApplication Event (" << e.GetName() << "), INFO: "<< "" << "\n";

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	// Application Loop
	void Application::Run(void)
	{
		WindowResizeEvent e(1280, 720);
		std::cout << e.GetName();

		std::cout << "Run Loop\n";
		while (m_Running)
		{
			// Update All Layers
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			// Update Window
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}
