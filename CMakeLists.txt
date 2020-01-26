cmake_minimum_required(VERSION 3.10.0)
project (EulerAdventureReinvented)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Link our find scripts to find the corresponding files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

# We need vulkan... pronto!
find_package(Vulkan REQUIRED)
# We also need some computation thingies
find_package(glm REQUIRED)

# Lets find glfw
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Lets find freetype
find_package(Freetype REQUIRED)
message("Includes ${FREETYPE_INCLUDE_DIRS}")
message("Libraries ${FREETYPE_LIBRARIES}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/")


# Include paths
include_directories (${Vulkan_INCLUDE_DIR})
include_directories (${GLFW_INCLUDE_DIRS})
include_directories (${FREETYPE_INCLUDE_DIRS})
include_directories (${CMAKE_CURRENT_SOURCE_DIR})

# Euler Engine
#add_definitions("-DEE_USE_UNICODE")
add_subdirectory(EulerEngine/source)
set_property(TARGET EulerEngine PROPERTY FOLDER "Core")

# Main Game
add_subdirectory(source)
set_property(TARGET EulerAdventure PROPERTY FOLDER "Project")
