-- Basic math types (Vector, Colour, Matrix...)

project "Lib-Math"
	kind "StaticLib"
	language "C"
	files { "**.h", "**.c", "premake4.lua" }
	vpaths { [""] = { "../Libraries/Math" } }
	includedirs { ".", ".." }
	location ( "../../Projects/" .. os.get() .. "/" .. _ACTION )
	
	-- Linux specific stuff
	configuration "linux"
		targetextension ".a"
		buildoptions { "-fms-extensions" } -- Unnamed struct/union fields within structs/unions
		configuration "Debug" targetname "libmathd"
		configuration "Release" targetname "libmath"
	
	-- Windows specific stuff
	configuration "windows"
		targetextension ".lib"
		buildoptions { "/wd4201 /wd4996" } -- C4201: nameless struct/union, C4996: This function or variable may be unsafe.
		configuration "Debug" targetname "mathd"
		configuration "Release" targetname "math"
