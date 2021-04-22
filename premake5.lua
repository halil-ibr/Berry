workspace "Berry"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Berry"
    location "Berry"
    kind "SharedLib"
    language "C++"
    staticruntime "On"

    pchheader "brpch.h"
    pchsource "Berry/src/brpch.cpp"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "BR_PLATFORM_WINDOWS",
            "BR_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "BR_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "BR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BR_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "Berry/vendor/spdlog/include",
        "Berry/src"
    }

    links
    {
        "Berry"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "BR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "BR_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "BR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BR_DIST"
        optimize "On"
