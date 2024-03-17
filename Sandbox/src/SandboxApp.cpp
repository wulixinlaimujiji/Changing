#include <Changing.h>

#include "imgui/imgui.h"

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

	//virtual void OnImGuiRender() override
	//{
	//	ImGui::Begin("Test");
	//	ImGui::Text("Hello World");
	//	ImGui::End();
	//}

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
	}
	~Sandbox() {}
};

Changing::Application* Changing::CreateApplication()
{
	return new Sandbox();
}