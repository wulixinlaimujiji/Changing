#pragma once
#include "chngpch.h"
#include "Changing/Core/Window.h"

#ifdef CHNG_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Changing
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
		#ifdef CHNG_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
		#else
			CHNG_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}

}