-- premake5.lua
ROOT = ".."
PRJ_NAME = "logging" --[[ MODIFY ]]
DEFAULT_TEST = "test" --[[ MODIFY ]]
-- workspace
workspace(PRJ_NAME)
   -- build options
   configurations { "debug", "release", "dist" }
   -- startproject
   startproject(DEFAULT_TEST)
   -- console
   kind "ConsoleApp"
   -- cpp
   language "C++"
   cppdialect "C++Latest"
   -- includedirs
   includedirs {
      ROOT,
      ROOT .. "/src",
      ROOT .. "/vendor",
   }
   -- files
   files {
      ROOT .. "/vendor/**",
   }
   -- bin
   -- bin :: targetdir
   targetdir(ROOT .. "/bin/%{cfg.buildcfg}/%{prj.name}")
   -- bin :: objdir
   objdir(ROOT .. "/bin/obj/%{cfg.system}_%{cfg.buildcfg}/%{prj.name}")
   -- debug
   debugger "GDB"
   -- config
   -- config :: debug
   filter "configurations:debug"
      -- symbols
      symbols "On"
      -- define
      defines { "CONFIG_DEBUG" }
   -- config :: fast
   filter "configurations:release"
      -- optimize
      optimize "On"
      -- define
      defines { "CONFIG_RELEASE" }
      -- linkoptions
      linkoptions{ "-Ofast" }
   -- config :: dist
   filter "configurations:dist"
      -- optimize
      optimize "On"
      -- define
      defines { "CONFIG_DIST" }
      -- linkoptions
      linkoptions { "-Ofast" }
-- project
-- project :: lib
project(PRJ_NAME)
   -- staticlib
   kind "StaticLib"
   -- includedirs
   includedirs {
      ROOT .. "/src",
      ROOT .. "/vendor",
   }
   -- files
   files {
      ROOT .. "/src/**",
      ROOT .. "/vendor/**",
   }
   -- obj
   objdir(ROOT .. "/bin/obj/%{cfg.system}_%{cfg.buildcfg}")
   -- targetdir
   targetdir(ROOT .. "/lib/%{cfg.buildcfg}")
-- project :: tests
-- project :: tests :: test
project "test"
   -- includedirs
   includedirs {
      ROOT .. "/include",
   }
   -- files
   files {
      ROOT .. "/tests/%{prj.name}.cpp",
      --[[ INSERT ADDITIONAL FILES HERE ]]
      ROOT .. "/vendor/**",
   }
   -- link
   links { PRJ_NAME, --[[ INSERT ADDITIONAL LINKS HERE ]] }
--[[ INSERT ADDITIONAL TESTS HERE ]]