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

include "Changing/vendor/GLFW"
include "Changing/vendor/Glad"
include "Changing/vendor/imgui"

project "Changing"
	location "Changing"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CHNG_PLATFORM_WINDOWS",
			"CHNG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "CHNG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CHNG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CHNG_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CHNG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHNG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CHNG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CHNG_DIST"
		runtime "Release"
		optimize "On"