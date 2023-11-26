#pragma once
#include "MittensLib/Core.h";
#include "MittensLib/Events/Event.h";
#include <string>;

namespace Mittens
{
	class MTS_API Layer
	{
	public:
		Layer(const std::string name = "Layer");
		Layer(const std::string& name);
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_LayerName; }
	private:
		std::string m_LayerName;
		bool m_Enabled;
	};

}