project "GLFW"
    kind "StaticLib"
    language "C"

    targetdir("bin\\" .. outputdir .. "\\%{prj.name}")
    objdir("bin-int\\" .. outputdir .. "\\%{prj.name}")

    files
    {
        "include/GLFW/glfw3.h",
        "include/GLFW/glfw3native.h"
    }

    filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		defines 
		{ 
			"_GLFW_WIN32"
		}


    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"