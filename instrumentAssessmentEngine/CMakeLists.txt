cmake_minimum_required(VERSION 3.10)
project(instrumentAssessmentEngine)

# 1. Define some well-known folders:
# - Place for compile binaries
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
# - Root for include files
set(INCLUDE_HOME ${PROJECT_SOURCE_DIR}/src)
# - In-house cmake functions
set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-lib)
# - set boost home
set(BOOST_ROOT /home/boost_1_66_0)
# - set TODO FIX
#set (CMAKE_TEST ${PROJECT_SOURCE_DIR}/src)

# Print some stuff
message("--> CMake extra functions: " ${CMAKE_MODULE_PATH})
message("--> Binaries: " ${CMAKE_BINARY_DIR})
message("--> Include base path: " ${INCLUDE_HOME})

# 2. Load in-house cmake modules
message("--> Loading CMake modules: ")
#include(${CMAKE_MODULE_PATH}/CMakeBoostTest.cmake)
#include(${CMAKE_MODULE_PATH}/CMakeAuxFunctions.cmake)
include(${CMAKE_MODULE_PATH}/CMakeAuxFunctions.cmake)
# TODO FIX
#include(${CMAKE_TEST}/CMakeLists.txt)

# 3. Set CMake environment
# - Set folders
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# - C++ file filter for adding files in cmake's projects
set(CXX_FILE_EXTENSIONS "*.h"  "*.cpp")

# 4. Set Compilation environment
include_directories(${INCLUDE_HOME})
add_definitions(-std=gnu++14)

# include the cmake modules directory
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# 5. Add subdirs
add_subdirectory(src)
