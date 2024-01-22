#include <Changing.h>

class Sandbox : public Changing::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Changing::Application* Changing::CreateApplication()
{
	return new Sandbox();
}