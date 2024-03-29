project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Changing/vendor/spdlog/include",
		"%{wks.location}/Changing/src",
		"%{wks.location}/Changing/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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