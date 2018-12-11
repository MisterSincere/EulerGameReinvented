cmake_minimum_required(VERSION 2.6)
project (EulerAdventure)

# Source files
set (EulerAdventure source/EulerAdventure.cpp)

# Filter
source_group ("" FILES ${EulerAdventure})

# SFML Library
link_directories ($ENV{ECA_SFML}/lib)

# Includes
include_directories ($ENV{ECA_SFML}/include)

# Add source files
add_executable (EulerAdventure ${EulerAdventure})