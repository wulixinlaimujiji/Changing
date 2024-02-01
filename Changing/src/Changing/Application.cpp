#include "chngpch.h"
#include "Application.h"

#include "Changing/Log.h"

#include <GLFW/glfw3.h>

namespace Changing {

	// ���¼��ص�
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	// ���캯������������
	Application::Application()
	{
		// �������ڲ������¼��ص�
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application()
	{
	}

	// �����¼�
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		CHNG_CORE_TRACE("{0}", e);
	}

	// ����Ӧ�ó���
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	// �����ڹر��¼�
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
