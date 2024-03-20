#pragma once
#include "Changing/Core/Base.h"

#ifdef CHNG_PLATFORM_WINDOWS

extern Changing::Application* Changing::CreateApplication();

int main(int argc, char** argv)
{
	Changing::Log::Init();

	CHNG_PROFILE_BEGIN_SESSION("Startup", "ChangingProfile-Startup.json");
	auto app = Changing::CreateApplication();
	CHNG_PROFILE_END_SESSION();

	CHNG_PROFILE_BEGIN_SESSION("Runtime", "ChangingProfile-Runtime.json");
	app->Run();
	CHNG_PROFILE_END_SESSION();

	CHNG_PROFILE_BEGIN_SESSION("Startup", "ChangingProfile-Shutdown.json");
	delete app;
	CHNG_PROFILE_END_SESSION();
}

#endif
