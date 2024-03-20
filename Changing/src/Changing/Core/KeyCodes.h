#pragma once

namespace Changing
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define CHNG_KEY_SPACE           ::Changing::Key::Space
#define CHNG_KEY_APOSTROPHE      ::Changing::Key::Apostrophe    /* ' */
#define CHNG_KEY_COMMA           ::Changing::Key::Comma         /* , */
#define CHNG_KEY_MINUS           ::Changing::Key::Minus         /* - */
#define CHNG_KEY_PERIOD          ::Changing::Key::Period        /* . */
#define CHNG_KEY_SLASH           ::Changing::Key::Slash         /* / */
#define CHNG_KEY_0               ::Changing::Key::D0
#define CHNG_KEY_1               ::Changing::Key::D1
#define CHNG_KEY_2               ::Changing::Key::D2
#define CHNG_KEY_3               ::Changing::Key::D3
#define CHNG_KEY_4               ::Changing::Key::D4
#define CHNG_KEY_5               ::Changing::Key::D5
#define CHNG_KEY_6               ::Changing::Key::D6
#define CHNG_KEY_7               ::Changing::Key::D7
#define CHNG_KEY_8               ::Changing::Key::D8
#define CHNG_KEY_9               ::Changing::Key::D9
#define CHNG_KEY_SEMICOLON       ::Changing::Key::Semicolon     /* ; */
#define CHNG_KEY_EQUAL           ::Changing::Key::Equal         /* = */
#define CHNG_KEY_A               ::Changing::Key::A
#define CHNG_KEY_B               ::Changing::Key::B
#define CHNG_KEY_C               ::Changing::Key::C
#define CHNG_KEY_D               ::Changing::Key::D
#define CHNG_KEY_E               ::Changing::Key::E
#define CHNG_KEY_F               ::Changing::Key::F
#define CHNG_KEY_G               ::Changing::Key::G
#define CHNG_KEY_H               ::Changing::Key::H
#define CHNG_KEY_I               ::Changing::Key::I
#define CHNG_KEY_J               ::Changing::Key::J
#define CHNG_KEY_K               ::Changing::Key::K
#define CHNG_KEY_L               ::Changing::Key::L
#define CHNG_KEY_M               ::Changing::Key::M
#define CHNG_KEY_N               ::Changing::Key::N
#define CHNG_KEY_O               ::Changing::Key::O
#define CHNG_KEY_P               ::Changing::Key::P
#define CHNG_KEY_Q               ::Changing::Key::Q
#define CHNG_KEY_R               ::Changing::Key::R
#define CHNG_KEY_S               ::Changing::Key::S
#define CHNG_KEY_T               ::Changing::Key::T
#define CHNG_KEY_U               ::Changing::Key::U
#define CHNG_KEY_V               ::Changing::Key::V
#define CHNG_KEY_W               ::Changing::Key::W
#define CHNG_KEY_X               ::Changing::Key::X
#define CHNG_KEY_Y               ::Changing::Key::Y
#define CHNG_KEY_Z               ::Changing::Key::Z
#define CHNG_KEY_LEFT_BRACKET    ::Changing::Key::LeftBracket   /* [ */
#define CHNG_KEY_BACKSLASH       ::Changing::Key::Backslash     /* \ */
#define CHNG_KEY_RIGHT_BRACKET   ::Changing::Key::RightBracket  /* ] */
#define CHNG_KEY_GRAVE_ACCENT    ::Changing::Key::GraveAccent   /* ` */
#define CHNG_KEY_WORLD_1         ::Changing::Key::World1        /* non-US #1 */
#define CHNG_KEY_WORLD_2         ::Changing::Key::World2        /* non-US #2 */

/* Function keys */
#define CHNG_KEY_ESCAPE          ::Changing::Key::Escape
#define CHNG_KEY_ENTER           ::Changing::Key::Enter
#define CHNG_KEY_TAB             ::Changing::Key::Tab
#define CHNG_KEY_BACKSPACE       ::Changing::Key::Backspace
#define CHNG_KEY_INSERT          ::Changing::Key::Insert
#define CHNG_KEY_DELETE          ::Changing::Key::Delete
#define CHNG_KEY_RIGHT           ::Changing::Key::Right
#define CHNG_KEY_LEFT            ::Changing::Key::Left
#define CHNG_KEY_DOWN            ::Changing::Key::Down
#define CHNG_KEY_UP              ::Changing::Key::Up
#define CHNG_KEY_PAGE_UP         ::Changing::Key::PageUp
#define CHNG_KEY_PAGE_DOWN       ::Changing::Key::PageDown
#define CHNG_KEY_HOME            ::Changing::Key::Home
#define CHNG_KEY_END             ::Changing::Key::End
#define CHNG_KEY_CAPS_LOCK       ::Changing::Key::CapsLock
#define CHNG_KEY_SCROLL_LOCK     ::Changing::Key::ScrollLock
#define CHNG_KEY_NUM_LOCK        ::Changing::Key::NumLock
#define CHNG_KEY_PRINT_SCREEN    ::Changing::Key::PrintScreen
#define CHNG_KEY_PAUSE           ::Changing::Key::Pause
#define CHNG_KEY_F1              ::Changing::Key::F1
#define CHNG_KEY_F2              ::Changing::Key::F2
#define CHNG_KEY_F3              ::Changing::Key::F3
#define CHNG_KEY_F4              ::Changing::Key::F4
#define CHNG_KEY_F5              ::Changing::Key::F5
#define CHNG_KEY_F6              ::Changing::Key::F6
#define CHNG_KEY_F7              ::Changing::Key::F7
#define CHNG_KEY_F8              ::Changing::Key::F8
#define CHNG_KEY_F9              ::Changing::Key::F9
#define CHNG_KEY_F10             ::Changing::Key::F10
#define CHNG_KEY_F11             ::Changing::Key::F11
#define CHNG_KEY_F12             ::Changing::Key::F12
#define CHNG_KEY_F13             ::Changing::Key::F13
#define CHNG_KEY_F14             ::Changing::Key::F14
#define CHNG_KEY_F15             ::Changing::Key::F15
#define CHNG_KEY_F16             ::Changing::Key::F16
#define CHNG_KEY_F17             ::Changing::Key::F17
#define CHNG_KEY_F18             ::Changing::Key::F18
#define CHNG_KEY_F19             ::Changing::Key::F19
#define CHNG_KEY_F20             ::Changing::Key::F20
#define CHNG_KEY_F21             ::Changing::Key::F21
#define CHNG_KEY_F22             ::Changing::Key::F22
#define CHNG_KEY_F23             ::Changing::Key::F23
#define CHNG_KEY_F24             ::Changing::Key::F24
#define CHNG_KEY_F25             ::Changing::Key::F25

/* Keypad */
#define CHNG_KEY_KP_0            ::Changing::Key::KP0
#define CHNG_KEY_KP_1            ::Changing::Key::KP1
#define CHNG_KEY_KP_2            ::Changing::Key::KP2
#define CHNG_KEY_KP_3            ::Changing::Key::KP3
#define CHNG_KEY_KP_4            ::Changing::Key::KP4
#define CHNG_KEY_KP_5            ::Changing::Key::KP5
#define CHNG_KEY_KP_6            ::Changing::Key::KP6
#define CHNG_KEY_KP_7            ::Changing::Key::KP7
#define CHNG_KEY_KP_8            ::Changing::Key::KP8
#define CHNG_KEY_KP_9            ::Changing::Key::KP9
#define CHNG_KEY_KP_DECIMAL      ::Changing::Key::KPDecimal
#define CHNG_KEY_KP_DIVIDE       ::Changing::Key::KPDivide
#define CHNG_KEY_KP_MULTIPLY     ::Changing::Key::KPMultiply
#define CHNG_KEY_KP_SUBTRACT     ::Changing::Key::KPSubtract
#define CHNG_KEY_KP_ADD          ::Changing::Key::KPAdd
#define CHNG_KEY_KP_ENTER        ::Changing::Key::KPEnter
#define CHNG_KEY_KP_EQUAL        ::Changing::Key::KPEqual

#define CHNG_KEY_LEFT_SHIFT      ::Changing::Key::LeftShift
#define CHNG_KEY_LEFT_CONTROL    ::Changing::Key::LeftControl
#define CHNG_KEY_LEFT_ALT        ::Changing::Key::LeftAlt
#define CHNG_KEY_LEFT_SUPER      ::Changing::Key::LeftSuper
#define CHNG_KEY_RIGHT_SHIFT     ::Changing::Key::RightShift
#define CHNG_KEY_RIGHT_CONTROL   ::Changing::Key::RightControl
#define CHNG_KEY_RIGHT_ALT       ::Changing::Key::RightAlt
#define CHNG_KEY_RIGHT_SUPER     ::Changing::Key::RightSuper
#define CHNG_KEY_MENU            ::Changing::Key::Menu