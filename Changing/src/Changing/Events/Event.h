#pragma once

#include "chngpch.h"
#include "Changing/Core.h"

namespace Changing {

	// 事件类型
	enum class EventType
	{
		Node = 0,
		WindowClose, WindowResize, WindowFocus, WindowLosFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// 事件类别
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

// 用于生成事件类型和类别的宏
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// 事件基类
	class CHANGING_API Event
	{
	public:
		bool Handled = false;  // 事件是否已处理标志
		virtual EventType GetEventType() const = 0;  // 获取事件类型
		virtual const char* GetName() const = 0;  // 获取事件名称
		virtual int GetCategoryFlags() const = 0;  // 获取事件类别标志
		virtual std::string ToString() const { return GetName(); } // 将事件转换为字符串表示

		// 检查事件是否属于指定类别
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	// 事件分发器类（用于分发特定类型的事件）
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		// 分发特定类型的事件，并调用对应的处理函数
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;  // 事件
	};

	// 重载输出运算符（用于将事件转换为字符串输出）
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}