#pragma once

#include "Changing.h"

class Sandbox2D : public Changing::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Changing::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Changing::Event& e) override;
private:
	Changing::OrthographicCameraController m_CameraController;

	Changing::Ref<Changing::VertexArray> m_SquareVA;
	Changing::Ref<Changing::Shader> m_FlatColorShader;

	Changing::Ref<Changing::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
