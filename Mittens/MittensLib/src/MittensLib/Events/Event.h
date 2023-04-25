#pragma once
#include <string>

namespace Mittens
{	
	enum EventCategory
	{
		NONE = 0,
		INPUT,
		APPLICATION
	};

	enum EventType
	{
		KEY_PRESSED, KEY_RELEASED,
		_MOUSE_MOVED, MOUSE_SCROLLED, MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED,
		WINDOW_CLOSED, WIDNOW_LOST_FOCUS, WINDOW_FOCUS, WINDOW_RESIZE, WINDOW_MOVED,
		APP_RENDER, APP_TICK, APP_UPDATE
	};

	class Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

	protected:
		Event() { }
	private:
		bool m_Handled;
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
}