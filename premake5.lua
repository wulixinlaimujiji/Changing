workspace "Changing"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Changing/vendor/GLFW/include"
IncludeDir["Glad"] = "Changing/vendor/Glad/include"
IncludeDir["ImGui"] = "Changing/vendor/imgui"
IncludeDir["glm"] = "Changing/vendor/glm"

group "Dependencies"
	include "Changing/vendor/GLFW"
	include "Changing/vendor/Glad"
	include "Changing/vendor/imgui"

group ""

project "Changing"
	location "Changing"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "chngpch.h"
	pchsource "Changing/src/chngpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CHNG_PLATFORM_WINDOWS",
			"CHNG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "CHNG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CHNG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CHNG_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Changing/vendor/spdlog/include",
		"Changing/src",
		"Changing/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Changing"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CHNG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHNG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CHNG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CHNG_DIST"
		runtime "Release"
		optimize "on"
