-- Copyright to Avram Traian. 2022 - 2022.
-- File created on July 22 2022.

workspace "moonlit"
	location "../../"

	configurations {
		"Debug", "Release", "Shipping"
	}

	platforms {
		"Win64"
	}

	filter "platforms:Win64"
		system "Windows"
		architecture "x86_64"
	filter ""

	startproject "MoonlitEd"

	IncludeDirectories = {}
	LibraryDirectories = {}
	LibraryNames = {}

	IncludeDirectories["Moonlit"] = "%{wks.location}/Moonlit/Source"

	Vulkan = os.getenv("VULKAN_SDK")
	IncludeDirectories["Vulkan"] = Vulkan.."Include"
	LibraryDirectories["Vulkan"] = Vulkan.."Lib"
	LibraryNames["Vulkan"] = "vulkan-1"

	group "Core"
		include "Dev-Core-Moonlit.lua"
	group ""

	group "Tools"
		include "Dev-Tools-MoonlitEd.lua"
	group ""

	group "ThirdParty"
	group ""