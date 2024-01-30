#include "chngpch.h"
#include "Application.h"

#include "Changing/Events/ApplicationEvent.h"
#include "Changing/Log.h"

namespace Changing {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CHNG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CHNG_TRACE(e);
		}

		while (true);
	}
}
