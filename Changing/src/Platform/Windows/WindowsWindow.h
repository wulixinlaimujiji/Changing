#pragma once

#include "Changing/Window.h"

#include <GLFW/glfw3.h>

namespace Changing {

	class WindowsWindow : public Window
	{
	public:
		// �������������
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		// ���´���
		void OnUpdate() override;

		// setter and getter
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		// ��ʼ���͹رմ���
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;  // GLFW����ָ��
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		} m_Data;  // �������ݶ���
	};

}
