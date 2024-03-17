#include <Changing.h>

class ExampleLayer : public Changing::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		if (Changing::Input::IsKeyPressed(CHNG_KEY_TAB))
		{
			CHNG_TRACE("Tab key is pressed (poll)!");
		}
	}

	void OnEvent(Changing::Event& event) override
	{
		if (event.GetEventType() == Changing::EventType::KeyPressed)
		{
			Changing::KeyPressedEvent& e = (Changing::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CHNG_KEY_TAB)
			{
				CHNG_TRACE("Tab key is pressed (event)!");
			}
			CHNG_TRACE("{0}", (char)e.GetKeyCode());
		}
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