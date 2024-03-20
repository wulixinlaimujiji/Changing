#pragma once

#include "Changing/Core/Base.h"
#include "Changing/Core/Timestep.h"
#include "Changing/Events/Event.h"

namespace Changing {
	
	class Layer
	{
	public:
		Layer(const std::string& debugname = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
