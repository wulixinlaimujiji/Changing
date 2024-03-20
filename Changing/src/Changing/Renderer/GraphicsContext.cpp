#include "chngpch.h"
#include "Changing/Renderer/GraphicsContext.h"

#include "Changing/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Changing {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    CHNG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		CHNG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
