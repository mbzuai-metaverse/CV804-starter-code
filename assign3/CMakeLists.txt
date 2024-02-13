# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(Assign3)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV, OpenGL, GLU, and GLUT packages
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Include directories for OpenGL, GLUT, and OpenCV
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

# Add executable target
file(GLOB all_sources src/*.cpp)
add_executable(assign3 ${all_sources})
target_include_directories(assign3 PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link libraries to the executable
target_link_libraries(assign3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${OpenCV_LIBS})
