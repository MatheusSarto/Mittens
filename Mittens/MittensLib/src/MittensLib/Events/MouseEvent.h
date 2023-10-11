#pragma once
#include "Events/Event.h"
#include "Core.h"

namespace Mittens
{
	class MTS_API MouseButton : public Event
	{
	protected:
		MouseButton(int button_code)
		{
			m_Button = button_code;
		}
		int m_Button;
	};

	class MTS_API MousePressedEvent : public MouseButton
	{
	public:
		MousePressedEvent(int button_code)
			: MouseButton(button_code)
		{
		}

		EVENT_CLASS_TYPE(Mouse_Button_Pressed)
		EVENT_CLASS_CATEGORY(InputCategory)
	protected:

	};

	class MTS_API MouseReleasedEvent : public MouseButton
	{
	public:
		MouseReleasedEvent(int button_code)
			: MouseButton(button_code)
		{
		}

		EVENT_CLASS_TYPE(Mouse_Button_Released)
		EVENT_CLASS_CATEGORY(InputCategory)
	protected:

	};

	class MTS_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent()
		{
		}

		EVENT_CLASS_TYPE(Mouse_Scrolled)
		EVENT_CLASS_CATEGORY(InputCategory)
	protected:
		float m_xOffSet;
		float m_yOffSet;
	};

	class MTS_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent()
		{
		}

		EVENT_CLASS_TYPE(Mouse_Moved)
		EVENT_CLASS_CATEGORY(InputCategory)
	protected:
		float m_MouseX;
		float m_MouseY;
	};
}
