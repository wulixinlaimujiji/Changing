#pragma once

#ifdef CHNG_PLATFORM_WINDOWS

extern Changing::Application* Changing::CreateApplication();

int main(int argc, char** argv)
{
	Changing::Log::Init();
	CHNG_CORE_WARN("Initialized Log!");
	int a = 5;
	CHNG_INFO("Hello! Var={0}", a);

	auto app = Changing::CreateApplication();
	app->Run();
	delete app;
}

#endif
