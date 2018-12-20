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

add_subdirectory(EulerEngine/source)

add_subdirectory(source)

add_dependencies(EulerAdventure EulerEngine)