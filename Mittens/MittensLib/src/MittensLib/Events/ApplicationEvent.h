#pragma once

#include "Events/Event.h"
#include "Core.h"

namespace Mittens
{
	class MTS_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) 
		: m_Width(width), m_Height(height)
			{ }

		inline unsigned int GetWidht()  { return m_Width;  }
		inline unsigned int GetHeight() { return m_Height; }

		EVENT_CLASS_TYPE(Window_Resize)
		EVENT_CLASS_CATEGORY(ApplicationCategory)

	private:
		unsigned int m_Width, m_Height;
	};

	class MTS_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		
		EVENT_CLASS_TYPE(Window_Closed)
		EVENT_CLASS_CATEGORY(ApplicationCategory)
	};
}