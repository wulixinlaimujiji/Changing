#pragma once
#include "chngpch.h"
#include "Changing/Core/Input.h"

#ifdef CHNG_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Changing {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
		#ifdef CHNG_PLATFORM_WINDOWS
			return CreateScope<WindowsInput>();
		#else
			CHNG_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}

}
