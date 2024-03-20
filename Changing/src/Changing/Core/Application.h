#pragma once

#include "Changing/Core/Core.h"

#include "Changing/Core/Window.h"
#include "Changing/Core/LayerStack.h"
#include "Changing/Events/Event.h"
#include "Changing/Events/ApplicationEvent.h"

#include "Changing/Core/Timestep.h"

#include "Changing/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Changing {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication();

}
