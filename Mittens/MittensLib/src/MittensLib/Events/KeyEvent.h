#pragma once

#include "Events/Event.h"

namespace Mittens
{
	class MTS_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(KeyboardCategory | InputCategory)
	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) { }

		int m_KeyCode;
	};

	class MTS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {  }

		inline int GetRepeatCount() { return m_RepeatCount; }

		EVENT_CLASS_TYPE(Key_Pressed)
	private:
		int m_RepeatCount;
	};

	class MTS_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) { }

		EVENT_CLASS_TYPE(Key_Released)
	};

}

