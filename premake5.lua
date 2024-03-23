include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Changing"
	architecture "x86_64"
	startproject "ChangingShow"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Changing/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Changing/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Changing/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Changing/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Changing/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Changing/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Changing/vendor/GLFW"
	include "Changing/vendor/Glad"
	include "Changing/vendor/imgui"
group ""

include "Changing"
include "Sandbox"
include "ChangingShow"