project "RPGHandler"
    kind "ConsoleApp"
    languange "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs
	{
		"src",
        "include",
        "vendor/imgui"
        "vendor/Vulkan/Include"
	}

    libdirs
    {
        "vendor/Vulkan/Lib"
    }

    builddependencies 
    {
        "vendor/Vulkan/Lib/vulkan-1.lib"
    }

    defines
    {
        "WINDOWS",
        "LINUX",
        "MAC"
    }

    filter {"configurations:Debug"}
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release"}
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
    
    links
    {
        "GLFW"
    }