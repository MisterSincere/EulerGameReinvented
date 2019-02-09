#--------------------------------------------------------------------------------------------------
#
# EULER ADVENTURE Project Setup
#
#--------------------------------------------------------------------------------------------------


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

# EulerEngine library
if (CMAKE_GENERATOR MATCHES Win64)
	link_directories ("${CMAKE_SOURCE_DIR}/lib/Win64/")
else()
	link_directories ("${CMAKE_SOURCE_DIR}/lib/Win64/")
endif()

# Includes
include_directories (coretools)
include_directories (eca)
include_directories (gfx)
include_directories (scenes)
include_directories (${CMAKE_SOURCE_DIR}/source)
include_directories (${CMAKE_SOURCE_DIR}/EulerEngine/source)


# Defines
add_definitions("-DASSETS_PATH=\"${CMAKE_SOURCE_DIR}/assets/\"")


# Add source files
add_executable (EulerAdventure ${EulerAdventure} ${GFX} ${ECA} ${SCENES} ${CORETOOLS})
add_dependencies(EulerAdventure EulerEngine)

# EulerEngine library
target_link_libraries (EulerAdventure
	debug Debug/EulerEngine
	optimized Release/EulerEngine)