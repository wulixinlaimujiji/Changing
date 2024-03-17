#pragma once

#include "Core.h"
#include "Window.h"
#include "Changing/LayerStack.h"
#include "Changing/Events/Event.h"
#include "Changing/Events/ApplicationEvent.h"

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
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		// �����ڹر��¼�
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;  // ���ڶ���
		bool m_Running = true;  // Ӧ�ó�������״̬��־
		LayerStack m_LayerStack;
	};
	
	// ����Ӧ�ó������
	Application* CreateApplication();

}

