workspace "Changing"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Changing"
	location "Changing"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "chngpch.h"
	pchsource "Changing/src/chngpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CHNG_PLATFORM_WINDOWS",
			"CHNG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CHNG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CHNG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CHNG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Changing/src"
	}

	links
	{
		"Changing"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CHNG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHNG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CHNG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CHNG_DIST"
		optimize "On"