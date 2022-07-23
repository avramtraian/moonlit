-- Copyright to Avram Traian. 2022 - 2022.
-- File created on July 22 2022.

project "Moonlit"
	location "%{wks.location}/Moonlit"

	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	rtti "Off"
	exceptionhandling "Off"
	characterset "Unicode"

	targetname "Moonlit-Core"
	targetdir "%{wks.location}/Binaries/%{cfg.platform}/%{cfg.buildcfg}"
	objdir "%{wks.location}/Intermediates/Build/%{prj.name}/%{cfg.buildcfg}"

	pchheader "MoonlitPCH.h"
	pchsource "../Source/MoonlitPCH.cpp"

	files {
		"%{prj.location}/Source/**.h",
		"%{prj.location}/Source/**.cpp",

		"%{prj.location}/Build/**.lua"
	}

	defines {
		"MOON_BUILD_SHARED_LIB"
	}

	includedirs {
		"%{prj.location}/Source",

		IncludeDirectories["Vulkan"]
	}

	forceincludes {
		"MoonlitPCH.h"
	}

	libdirs {
		LibraryDirectories["Vulkan"]
	}

	links {
		LibraryNames["Vulkan"]
	}

	filter "platforms:Win64"
		defines {
			"MOON_PLATFORM_WINDOWS=(1)",
			"MOON_PLATFORM_WIN64=(1)"
		}

		systemversion "latest"
	filter ""

	filter "configurations:Debug"
		defines {
			"MOON_BUILD_DEBUG=(1)"
		}

		optimize "Off"
		symbols "On"
		runtime "Debug"
	filter ""

	filter "configurations:Release"
		defines {
			"MOON_BUILD_RELEASE=(1)"
		}

		optimize "On"
		symbols "On"
		runtime "Release"
	filter ""

	filter "configurations:Shipping"
		defines {
			"MOON_BUILD_SHIPPING=(1)"
		}
		
		optimize "Speed"
		symbols "Off"
		runtime "Release"
	filter ""