#pragma once
#include "Events/IObserver.h"
#include <forward_list>
#include <map>
namespace Mittens
{
	// Subject Interface
	class ISubject
	{
	public:
		ISubject();
		virtual ~ISubject();
		virtual void AddOserver(int eventType, IObserver* observer)
		{
			auto it = m_Observers.find(eventType);
			if (it == m_Observers.end())
			{
				m_Observers[eventType] = Observers();
			}

			m_Observers[eventType].push_front(observer);
		}
		virtual void RemoveObserver(IObserver* observer)
		{

		}
		virtual void NotifyAll() 
		{
			for (ObserversMap::iterator it = m_Observers.begin(); it != m_Observers.end(); ++it)
			{
				for (auto& o : m_Observers[it->first]) {
					o->OnEvent();
				}
			}
		}
		virtual void Notify(int eventType)
		{
			for (auto& o : m_Observers[eventType]) {
				o->OnEvent();
			}
		}
	private:
		typedef std::forward_list<IObserver*> Observers;
		typedef std::map<int, Observers> ObserversMap;
		
		ObserversMap m_Observers;
	};
}
