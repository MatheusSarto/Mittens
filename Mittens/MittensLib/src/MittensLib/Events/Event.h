#pragma once
#include <string>
#include <vector>

namespace Mittens
{	
	enum EventCategory
	{
		None = 0,
		Input,
		Application
	};

	enum class EventType
	{
		Key_Pressed, Key_Pressed,
		Mouse_Moved, Mouse_Scrolled, Mouse_Button_Pressed, Mouse_Button_Released,
		Window_Closed, Window_Lost_Focus, Window_Focus, Window_Resize, Window_Moved,
		App_Render, App_Tick, App_Update
	};

	class Event
	{
	public:
		
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		bool m_Handled;
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
} 