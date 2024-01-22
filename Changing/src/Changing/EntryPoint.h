#pragma once

#ifdef CHNG_PLATFORM_WINDOWS

extern Changing::Application* Changing::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Changing::CreateApplication();
	app->Run();
	delete app;
}

#endif