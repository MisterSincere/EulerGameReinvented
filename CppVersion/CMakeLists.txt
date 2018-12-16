cmake_minimum_required(VERSION 3.13.1)
project (EulerAdventure)

# Source files
file (GLOB CORETOOLS "source/coretools/*.h" "source/coretools/*.cpp")
file (GLOB ECA "source/eca/*.h" "source/eca/*.cpp")
file (GLOB GFX "source/gfx/*.h" "source/gfx/*.cpp")
file (GLOB SCENES "source/scenes/*.h" "source/scenes/*.cpp")
file (GLOB EulerAdventure "source/*.h" "source/*.cpp")

# Filter
source_group ("CORETOOLS" FILES ${CORETOOLS})
source_group ("GFX" FILES ${GFX})
source_group ("ECA" FILES ${ECA})
source_group ("SCENES" FILES ${SCENES})
source_group ("" FILES ${EulerAdventure})

# SFML Library
link_directories ($ENV{ECA_SFML}/lib)

# Includes
include_directories ($ENV{ECA_SFML}/include)
include_directories (source/coretools)
include_directories (source/eca)
include_directories (source/gfx)
include_directories (source/scenes)
include_directories (source)

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
add_compile_definitions(SFML_STATIC)