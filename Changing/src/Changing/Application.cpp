#include "chngpch.h"
#include "Application.h"

#include "Changing/Log.h"

#include <GLFW/glfw3.h>

namespace Changing {

	// 绑定事件回调
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	// 构造函数和析构函数
	Application::Application()
	{
		// 创建窗口并设置事件回调
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application()
	{
	}

	// 处理事件
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		CHNG_CORE_TRACE("{0}", e);
	}

	// 运行应用程序
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	// 处理窗口关闭事件
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
