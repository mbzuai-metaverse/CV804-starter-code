# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(Assign4)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
file(GLOB all_sources src/*.cpp)
add_executable(assign4 ${all_sources})
target_include_directories(assign4 PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link libraries to the executable
target_link_libraries(assign4 ${OpenCV_LIBS})
