#pragma once

#include <glm/glm.hpp>

#include "Changing/Core/KeyCodes.h"
#include "Changing/Core/MouseCodes.h"

namespace Changing {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}
