#pragma once

#include "Core.h"

namespace Changing {

	class CHANGING_API Application
	{
	public:
		Application();
		virtual ~Application();
	
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
