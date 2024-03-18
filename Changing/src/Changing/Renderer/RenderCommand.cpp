#include "chngpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Changing {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
