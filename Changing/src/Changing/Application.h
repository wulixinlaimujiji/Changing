#pragma once

#include "Core.h"
#include "Window.h"
#include "Changing/LayerStack.h"
#include "Changing/Events/Event.h"
#include "Changing/Events/ApplicationEvent.h"

namespace Changing {

	// 应用程序类
	class CHANGING_API Application
	{
	public:
		// 构造和析构函数
		Application();
		virtual ~Application();
	
		// 运行应用程序
		void Run();

		// 处理事件
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		// 处理窗口关闭事件
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;  // 窗口对象
		bool m_Running = true;  // 应用程序运行状态标志
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};
	
	// 创建应用程序对象
	Application* CreateApplication();

}

