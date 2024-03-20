workspace "Changing"
	architecture "x86_64"
	startproject "ChangingShow"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Changing/vendor/GLFW/include"
IncludeDir["Glad"] = "Changing/vendor/Glad/include"
IncludeDir["ImGui"] = "Changing/vendor/imgui"
IncludeDir["glm"] = "Changing/vendor/glm"
IncludeDir["stb_image"] = "Changing/vendor/stb_image"

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
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
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

project "ChangingShow"
	location "ChangingShow"
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
