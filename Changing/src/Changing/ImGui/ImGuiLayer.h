#pragma once

#include "Changing/Core/Layer.h"

#include "Changing/Events/ApplicationEvent.h"
#include "Changing/Events/KeyEvent.h"
#include "Changing/Events/MouseEvent.h"

namespace Changing {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
