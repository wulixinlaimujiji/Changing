#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Changing {

	// Ӧ�ó�����
	class CHANGING_API Application
	{
	public:
		// �������������
		Application();
		virtual ~Application();
	
		// ����Ӧ�ó���
		void Run();

		// �����¼�
		void OnEvent(Event& e);

	private:
		// �����ڹر��¼�
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;  // ���ڶ���
		bool m_Running = true;  // Ӧ�ó�������״̬��־
	};
	
	// ����Ӧ�ó������
	Application* CreateApplication();

}

