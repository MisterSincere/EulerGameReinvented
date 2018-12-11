cmake_minimum_required(VERSION 3.13.1)
project (EulerAdventure)

# Source files
set (EulerAdventure source/Tuna.h source/Tuna.cpp source/EulerAdventure.cpp)

# Filter
source_group ("" FILES ${EulerAdventure})

# SFML Library
link_directories ($ENV{ECA_SFML}/lib)

# Includes
include_directories ($ENV{ECA_SFML}/include)

# Add source files
add_executable (EulerAdventure ${EulerAdventure})

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