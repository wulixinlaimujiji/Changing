#pragma once

#include "entt.hpp"

#include "Changing/Core/Timestep.h"

namespace Changing {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(Timestep ts);
	private:
		entt::registry m_Registry;
	
		friend class Entity;
	};

}
