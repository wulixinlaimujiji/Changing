#include "chngpch.h"
#include "Changing/Renderer/VertexArray.h"

#include "Changing/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Changing {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    CHNG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		CHNG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
