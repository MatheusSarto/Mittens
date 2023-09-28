#pragma once
#include <string>
#include <vector>
#include<map>
#include<forward_list>
#include "Events/EventHandler.h"

namespace Mittens
{	
	enum EventCategory
	{
		None = 0,
		Input,
		e_Application
	};

	enum class EventType
	{
		Key_Pressed, Key_Released,
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

	class EventQueue
	{
	// ------EVENT QUEUE INTERFACE------
	public:

		friend class Application;

		void QueueEvent(EventType eventType, EventHandler* handler)
		{
			auto it = m_Handlers.find(eventType);
			if (it == m_Handlers.end())
			{
				m_Handlers[eventType] = Handlers();
			}

			m_Handlers[eventType].push_front(handler);
		}
	
		typedef std::forward_list<EventHandler*> Handlers;
		typedef std::map<EventType, Handlers> ObserversMap;

		ObserversMap m_Handlers;
	private:
		EventQueue() {}

		void NotifyAll()
		{
			for (ObserversMap::iterator it = m_Handlers.begin(); it != m_Handlers.end(); ++it)
			{
				for (auto& o : m_Handlers[it->first]) {
					o->OnEvent();
				}
			}
		}
		void Notify(EventType eventType)
		{
			for (auto& o : m_Handlers[eventType]) {
				o->OnEvent();
			}
		}

		static void Dispatch() {}
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
} 