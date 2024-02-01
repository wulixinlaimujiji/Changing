#pragma once

#include "chngpch.h"

#include "Changing/Core.h"
#include "Changing/Events/Event.h"

namespace Changing {

	// ��������
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Changing Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// ����ϵͳ�Ĵ��ڽӿ�
	class CHANGING_API Window
	{
	public:
		// �¼��ص���������
		using EventCallbackFn = std::function<void(Event&)>;

		// ��������
		virtual ~Window() {}

		// ���´���
		virtual void OnUpdate() = 0;

		// setter and getter
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// ��������
		static Window* Create(const WindowProps& props = WindowProps());
	};

}