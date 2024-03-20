#pragma once

namespace Changing
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define CHNG_MOUSE_BUTTON_0      ::Changing::Mouse::Button0
#define CHNG_MOUSE_BUTTON_1      ::Changing::Mouse::Button1
#define CHNG_MOUSE_BUTTON_2      ::Changing::Mouse::Button2
#define CHNG_MOUSE_BUTTON_3      ::Changing::Mouse::Button3
#define CHNG_MOUSE_BUTTON_4      ::Changing::Mouse::Button4
#define CHNG_MOUSE_BUTTON_5      ::Changing::Mouse::Button5
#define CHNG_MOUSE_BUTTON_6      ::Changing::Mouse::Button6
#define CHNG_MOUSE_BUTTON_7      ::Changing::Mouse::Button7
#define CHNG_MOUSE_BUTTON_LAST   ::Changing::Mouse::ButtonLast
#define CHNG_MOUSE_BUTTON_LEFT   ::Changing::Mouse::ButtonLeft
#define CHNG_MOUSE_BUTTON_RIGHT  ::Changing::Mouse::ButtonRight
#define CHNG_MOUSE_BUTTON_MIDDLE ::Changing::Mouse::ButtonMiddle
