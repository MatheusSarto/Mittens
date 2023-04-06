workspace "Workspace1"
    architecture 
    {
        "x64",
        "x86"
    }

    configurations
    {
        "Debug",
        "Release",
        "Dist" --Dist Referes to "Distribution".
    }
    startproject "RPGHandler"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "RPGHandler/vendor/glfw"
include "RPGHandler"

newaction 
{
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries as well as visual studio files.",
    execute = function()
        print("Removing binaries")
        os.rmdir("./bin")
        print("Removing intermediate binaries")
        os.rmdir("./bin-int")
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}