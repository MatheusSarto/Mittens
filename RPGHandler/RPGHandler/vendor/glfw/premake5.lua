project "GLFW"
    kind "StaticLib"
    languange "C"

    targetdir("bin/" .. outputdir .. "%{proj.name}")
    objdir("bin-int/" .. outputdir .. "%{proj.name}")

    files
    {
        "include/GLFW/lib-vc2022/glfw3.dll
    }