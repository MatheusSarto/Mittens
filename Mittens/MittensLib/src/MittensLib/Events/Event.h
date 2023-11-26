#pragma once
#include <string>
#include <vector>
#include<map>
#include<forward_list>
#include "MittensLib/Core.h";
#include "Events/EventHandler.h"

namespace Mittens
{	
	enum EventCategory
	{
		None = 0,
		InputCategory        = BIT(0),
		ApplicationCategory  = BIT(1),
		KeyboardCategory     = BIT(2),
		MouseCategory        = BIT(3),
		MouseButtonCategory  = BIT(4)
	};

	enum class EventType
	{
		Key_Pressed, Key_Released,
		Mouse_Moved, Mouse_Scrolled, Mouse_Button_Pressed, Mouse_Button_Released,
		Window_Closed, Window_Lost_Focus, Window_Focus, Window_Resize, Window_Moved,
		App_Render, App_Tick, App_Update
	};

	class MTS_API Event
	{
		friend class EventDispatcher;
	public:
		
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		//virtual const char* ToString() const = 0;

		bool m_Handled;
	};


	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
} 