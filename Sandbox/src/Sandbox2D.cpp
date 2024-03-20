#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {}

void Sandbox2D::OnAttach() 
{
	CHNG_PROFILE_FUNCTION();

	m_CheckerboardTexture = Changing::Texture2D::Create("assets/textures/Checkerboard.png");
}
void Sandbox2D::OnDetach()
{
	CHNG_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Changing::Timestep ts)
{
	CHNG_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);

	{
		CHNG_PROFILE_SCOPE("Renderer Prep");
		Changing::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Changing::RenderCommand::Clear();
	}

	{
		CHNG_PROFILE_SCOPE("Renderer Draw");
		Changing::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Changing::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Changing::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Changing::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Changing::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	CHNG_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Changing::Event& e)
{
	m_CameraController.OnEvent(e);
}
