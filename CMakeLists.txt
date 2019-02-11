cmake_minimum_required(VERSION 3.13.1)
project (EulerAdventureReinvented)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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
link_directories (${CMAKE_CURRENT_SOURCE_DIR}/EulerEngine/source/freetype/lib64)

# Include paths
include_directories ($ENV{EE_GLM_PATH})
include_directories ($ENV{EE_VULKAN_PATH}/Include)
include_directories ($ENV{EE_GLFW_PATH}/include)
include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/EulerEngine/source/freetype/include)

# Euler Engine
add_subdirectory(EulerEngine/source)
set_property(TARGET EulerEngine PROPERTY FOLDER "Core")

# Main Game
add_subdirectory(source)
set_property(TARGET EulerAdventure PROPERTY FOLDER "Project")

# Vulkan and glfw library
target_link_libraries (EulerEngine general vulkan-1.lib glfw3.lib freetype.lib)
target_link_libraries (EulerAdventure general vulkan-1.lib glfw3.lib freetype.lib)
