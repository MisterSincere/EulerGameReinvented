cmake_minimum_required(VERSION 3.13.1)
project (EulerAdventure)

# Source files
file (GLOB CORETOOLS "source/coretools/*.h" "source/coretools/*.cpp")
file (GLOB ECA "source/eca/*.h" "source/eca/*.cpp")
file (GLOB GFX "source/gfx/*.h" "source/gfx/*.cpp")
file (GLOB EulerAdventure "source/*.h" "source/*.cpp")

# Filter
source_group ("CORETOOLS" FILES ${CORETOOLS})
source_group ("GFX" FILES ${GFX})
source_group ("ECA" FILES ${ECA})
source_group ("" FILES ${EulerAdventure})

# SFML Library
link_directories ($ENV{ECA_SFML}/lib)

# Includes
include_directories ($ENV{ECA_SFML}/include)

# Add source files
add_executable (EulerAdventure ${EulerAdventure} ${GFX} ${ECA} ${CORETOOLS})

# Debug libs
target_link_libraries (EulerAdventure debug
	sfml-graphics-s-d.lib
	sfml-window-s-d.lib
	sfml-audio-s-d.lib
	sfml-network-s-d.lib
	sfml-system-s-d.lib)

# Non Debug libs
target_link_libraries (EulerAdventure optimized
	sfml-graphics-s.lib
	sfml-window-s.lib
	sfml-audio-s.lib
	sfml-network-s.lib
	sfml-system-s.lib)

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