#pragma once

#include "Changing/Window.h"

#include <GLFW/glfw3.h>

namespace Changing {

	class WindowsWindow : public Window
	{
	public:
		// 构造和析构函数
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		// 更新窗口
		void OnUpdate() override;

		// setter and getter
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		// 初始化和关闭窗口
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;  // GLFW窗口指针
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		} m_Data;  // 窗口数据对象
	};

}
