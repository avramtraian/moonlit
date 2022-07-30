-- Copyright to Avram Traian. 2022 - 2022.
-- File created on July 23 2022.

project "MoonlitEd"
	location "%{wks.location}/MoonlitEd"

	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	rtti "Off"
	exceptionhandling "Off"
	characterset "Unicode"

	targetname "Moonlit-Ed"
	targetdir "%{wks.location}/Binaries/%{cfg.platform}/%{cfg.buildcfg}"
	objdir "%{wks.location}/Intermediates/Build/%{prj.name}/%{cfg.buildcfg}"

	pchheader "MoonlitEdPCH.h"
	pchsource "../../MoonlitEd/Source/MoonlitEdPCH.cpp"

	files {
		"%{prj.location}/Source/**.h",
		"%{prj.location}/Source/**.cpp"
	}

	defines {
		
	}

	includedirs {
		"%{prj.location}/Source",

		IncludeDirectories["Moonlit"]
	}

	forceincludes {
		"MoonlitEdPCH.h"
	}

	libdirs {

	}

	links {
		"Moonlit"
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

		kind "ConsoleApp"
	filter ""

	filter "configurations:Release"
		defines {
			"MOON_BUILD_RELEASE=(1)"
		}

		optimize "On"
		symbols "On"
		runtime "Release"

		kind "ConsoleApp"
	filter ""

	filter "configurations:Shipping"
		defines {
			"MOON_BUILD_SHIPPING=(1)"
		}
		
		optimize "Speed"
		symbols "Off"
		runtime "Release"

		kind "WindowedApp"
	filter ""