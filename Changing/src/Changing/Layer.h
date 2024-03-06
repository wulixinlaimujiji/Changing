#pragma once

#include "Changing/Core.h"
#include "Changing/Events/Event.h"

namespace Changing {
	
	class CHANGING_API Layer
	{
	public:
		Layer(const std::string& debugname = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}
