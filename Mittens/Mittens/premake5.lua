project "Mittens"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.cpp",
        "src/**h"
    }

    includedirs
    {
        "%{wks.location}/MittensLib/src",
        "%{wks.location}/MittensLib/vendor",
        "%{wks.location}/MittensLib/%{IncludeDir.glm}",
		"%{IncludeDir.glm}"
    }

    links
    {
        "MittensLib"
    }

    filter "system:windows"
		systemversion "latest"
    
		defines
		{
			"PLATAFORM_WINDOWS"
		}

        postbuildcommands
		{
			"{COPY} %{wks.location}/bin/" .. outputdir .. "/MittensLib/*.dll %{wks.location}/bin/" .. outputdir .. "/Sandbox", --  Delte this ? idk
			"{COPY} %{wks.location}/bin/" .. outputdir .. "/MittensLib/*.dll %{wks.location}/bin/" .. outputdir .. "/Mittens"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
      optimize "on"