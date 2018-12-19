

# Source files
file (GLOB CORETOOLS "coretools/*.h" "coretools/*.cpp")
file (GLOB ECA "eca/*.h" "eca/*.cpp")
file (GLOB GFX "gfx/*.h" "gfx/*.cpp")
file (GLOB SCENES "scenes/*.h" "scenes/*.cpp")
file (GLOB EulerAdventure "*.h" "*.cpp")

# Filter
source_group ("CORETOOLS" FILES ${CORETOOLS})
source_group ("GFX" FILES ${GFX})
source_group ("ECA" FILES ${ECA})
source_group ("SCENES" FILES ${SCENES})
source_group ("" FILES ${EulerAdventure})

# SFML Library
link_directories ($ENV{ECA_SFML_PATH}/lib)

# Includes
include_directories ($ENV{ECA_SFML_PATH}/include)
include_directories (coretools)
include_directories (eca)
include_directories (gfx)
include_directories (scenes)
include_directories (${CMAKE_SOURCE_DIR}/source)

# Add source files
add_executable (EulerAdventure ${EulerAdventure} ${GFX} ${ECA} ${SCENES} ${CORETOOLS})


# SFML libraries
target_link_libraries (EulerAdventure
	debug sfml-graphics-s-d.lib
	optimized sfml-graphics-s.lib)

target_link_libraries (EulerAdventure
	debug sfml-window-s-d.lib
	optimized sfml-window-s.lib)

target_link_libraries (EulerAdventure
	debug sfml-audio-s-d.lib
	optimized sfml-audio-s.lib)

target_link_libraries (EulerAdventure
	debug sfml-network-s-d.lib
	optimized sfml-network-s.lib)

target_link_libraries (EulerAdventure
	debug sfml-system-s-d.lib
	optimized sfml-system-s.lib)


# General libs
target_link_libraries (EulerAdventure general
	opengl32.lib
	freetype.lib
	winmm.lib
	gdi32.lib
	openal32.lib
	flac.lib
	vorbisenc.lib
	vorbisfile.lib
	vorbis.lib
	ogg.lib
	ws2_32.lib)


# Define for sfml to use static libraries
add_definitions(-DSFML_STATIC)

# Define fors the assets path
add_definitions("-DASSETS_PATH=\"${CMAKE_SOURCE_DIR}/assets/\"")




