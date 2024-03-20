#include <Changing.h>
#include <Changing/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Changing::Application
{
public:
	Sandbox() 
	{
		PushLayer(new Sandbox2D());
	}
	~Sandbox() {}
};

Changing::Application* Changing::CreateApplication()
{
	return new Sandbox();
}
