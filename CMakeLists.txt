cmake_minimum_required(VERSION 3.13.1)
project (EulerAdventureReinvented)

if (CMAKE_GENERATOR MATCHES Win64)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/Win64/")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/Win64/")
    SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/Win64/")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/Win32/")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/Win32/")
    SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/Win32/")
endif()

# Library paths
link_directories ($ENV{EE_VULKAN_PATH}/Lib)
link_directories ($ENV{EE_GLFW_PATH}/lib-vc2015)

# Include paths
include_directories ($ENV{EE_GLM_PATH})
include_directories ($ENV{EE_VULKAN_PATH}/Include)
include_directories ($ENV{EE_GLFW_PATH}/include)
include_directories (${CMAKE_CURRENT_SOURCE_DIR})

# Euler Engine
add_subdirectory(EulerEngine/source)

# Main Game
add_subdirectory(source)

# Vulkan and glfw library
target_link_libraries (EulerEngine general vulkan-1.lib glfw3.lib)
target_link_libraries (EulerAdventure general vulkan-1.lib glfw3.lib)

# SFML library to Euler Engine to unresolve stbi
# TODO When the sfml lib is no longer use include STB_IMPLENTATION define again
target_link_libraries (EulerEngine
	debug sfml-graphics-s-d.lib
	optimized sfml-graphics-s.lib)