# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(Assign1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV, OpenGL, GLU, and GLUT packages
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Include directories for OpenGL, GLUT, and OpenCV
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

# Add executable target
set(SOURCES main.cpp assign1.cpp)
set(HEADERS assign1.h)
add_executable(assign1 ${SOURCES} ${HEADERS})

# Link libraries to the executable
target_link_libraries(assign1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${OpenCV_LIBS})
