#pragma once

#include "Changing.h"

class ExampleLayer : public Changing::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Changing::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Changing::Event& e) override;
private:
	Changing::ShaderLibrary m_ShaderLibrary;
	Changing::Ref<Changing::Shader> m_Shader;
	Changing::Ref<Changing::VertexArray> m_VertexArray;

	Changing::Ref<Changing::Shader> m_FlatColorShader;
	Changing::Ref<Changing::VertexArray> m_SquareVA;

	Changing::Ref<Changing::Texture2D> m_Texture, m_LogoTexture;

	Changing::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
