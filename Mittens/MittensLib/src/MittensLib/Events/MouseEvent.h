#pragma once
#include "Event.h"
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

	class MTS_API MousePressed : public MouseButton
	{
	public:
		MousePressed(int button_code)
			: MouseButton(button_code)
		{
		}

		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
		EVENT_CLASS_CATEGORY(INPUT)
	protected:

	};

	class MTS_API MouseReleased : public MouseButton
	{
	public:
		MouseReleased(int button_code)
			: MouseButton(button_code)
		{
		}

		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
		EVENT_CLASS_CATEGORY(INPUT)
	protected:

	};

	class MTS_API MouseScrolled : public Event
	{
	public:
		MouseScrolled()
		{
		}

		EVENT_CLASS_TYPE(MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(INPUT)
	protected:
		float m_xOffSet;
		float m_yOffSet;
	};

	class MTS_API MouseMoved : public Event
	{
	public:
		MouseMoved()
		{
		}

		EVENT_CLASS_TYPE(_MOUSE_MOVED)
		EVENT_CLASS_CATEGORY(INPUT)
	protected:
		float m_MouseX;
		float m_MouseY;
	};
}
