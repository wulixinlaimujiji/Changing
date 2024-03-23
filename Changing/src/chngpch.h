#pragma once

#include "Changing/Core/PlatformDetection.h"

#ifdef CHANGING_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Changing/Core/Base.h"

#include "Changing/Core/Log.h"

#include "Changing/Debug/Instrumentor.h"

#ifdef CHNG_PLATFORM_WINDOWS
	#include <Windows.h>
#endif