#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

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

	private:
		// 处理窗口关闭事件
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;  // 窗口对象
		bool m_Running = true;  // 应用程序运行状态标志
	};
	
	// 创建应用程序对象
	Application* CreateApplication();

}

