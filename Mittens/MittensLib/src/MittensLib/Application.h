#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "MittensLib/LayerStack.h";

namespace Mittens
{
	class MTS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(void);

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be Defined on CLIENT
	Application* CreateApplication();
}
