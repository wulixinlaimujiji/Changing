#pragma once

#include "Changing/Core/Base.h"
#include "Changing/Core/KeyCodes.h"
#include "Changing/Core/MouseCodes.h"

namespace Changing {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}
