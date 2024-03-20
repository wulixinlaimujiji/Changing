#include "chngpch.h"
#include "Changing/Renderer/RenderCommand.h"

namespace Changing {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
