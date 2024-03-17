#include <Changing.h>

class ExampleLayer : public Changing::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		CHNG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Changing::Event& event) override
	{
		CHNG_TRACE("{0}", event);
	}

};

class Sandbox : public Changing::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Changing::ImGuiLayer());
	}
	~Sandbox() {}
};

Changing::Application* Changing::CreateApplication()
{
	return new Sandbox();
}