#include "chngpch.h"
#include "Changing/Scene/Entity.h"

namespace Changing {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene) {}

}
