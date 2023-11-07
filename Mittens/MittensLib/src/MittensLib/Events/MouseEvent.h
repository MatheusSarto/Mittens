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

	class MTS_API MouseButtonPressedEvent : public MouseButton
	{
	public:
		MouseButtonPressedEvent(int button_code)
			: MouseButton(button_code) { }

		EVENT_CLASS_TYPE(Mouse_Button_Pressed)
		EVENT_CLASS_CATEGORY(InputCategory)

	};

	class MTS_API MouseButtonReleasedEvent : public MouseButton
	{
	public:
		MouseButtonReleasedEvent(int button_code)
			: MouseButton(button_code) { }

		EVENT_CLASS_TYPE(Mouse_Button_Released)
		EVENT_CLASS_CATEGORY(InputCategory)
	};

	class MTS_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffSet, float yOffSet) 
			: m_xOffSet(xOffSet), m_yOffSet(yOffSet) { }

		inline float GetXOffSet() const { return m_xOffSet; }
		inline float GetYOffSet() const { return m_yOffSet; }

		EVENT_CLASS_TYPE(Mouse_Scrolled)
		EVENT_CLASS_CATEGORY(InputCategory)
	private:
		float m_xOffSet;
		float m_yOffSet;
	};

	class MTS_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) 
			: m_MouseX(x), m_MouseY(y) { }

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(Mouse_Moved)
		EVENT_CLASS_CATEGORY(InputCategory | InputCategory)
	private:
		float m_MouseX;
		float m_MouseY;
	};
}
