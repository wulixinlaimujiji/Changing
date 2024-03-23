#pragma once

#include "Changing/Core/Base.h"
#include "Changing/Core/Log.h"
#include "Changing/Scene/Scene.h"
#include "Changing/Scene/Entity.h"

namespace Changing {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}
