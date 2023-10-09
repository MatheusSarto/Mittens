project "MittensLib"
  kind "SharedLib"
  language "C++"
  cppdialect "C++17"
  staticruntime "off"

  targetname "%{prj.name}"
  location "%{wks.location}/%{prj.name}"
  targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
  objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "mtspch.h"
  pchsource "src/mtspch.cpp" -- <--- Visual Studio Only
  
  files
	{
		"src/**.h",
		"src/**.cpp",
    	"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl"
	}

  includedirs
	{
    "src",
	"src/MittensLib",
    "%{IncludeDir.GLFW}",
    "%{IncludeDir.ImGui}",
    "%{IncludeDir.glm}",
    "%{IncludeDir.VulkanSDK}"
	}

	links
	{
		"%{Library.WinSock}",
		"%{Library.WinMM}",
		"%{Library.WinVersion}",
		"%{Library.BCrypt}",
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PLATAFORM_WINDOWS",
			"BUILD_DLL"
		}

		links
		{
			"%{Library.WinSock}",
			"%{Library.WinMM}",
			"%{Library.WinVersion}",
			"%{Library.BCrypt}",
			"GLFW",
			"opengl32.lib"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"

		links
		{
			"%{Library.ShaderC_Release}",
			"%{Library.SPIRV_Cross_Release}",
			"%{Library.SPIRV_Cross_GLSL_Release}"
		}

	filter "configurations:Dist"
		defines "DIST"
		runtime "Release"
		optimize "on"

		links
		{
			"%{Library.ShaderC_Release}",
			"%{Library.SPIRV_Cross_Release}",
			"%{Library.SPIRV_Cross_GLSL_Release}"
		}