include "Dependencies.lua" 

workspace "Mittens"
    architecture "x64"
    startproject "Mittens"
    configurations
    {
        "Debug",
        "Release",
        "Dist" --Dist Referes to "Distribution".
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Projects
include "MittensLib/vendor/GLFW"
include "MittensLib/vendor/imgui"
include "MittensLib"
include "Mittens"
-- 


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

