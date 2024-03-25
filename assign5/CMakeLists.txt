# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(Assign5)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find FreeGLUT, OpenGL, and OpenMesh
find_package(FreeGLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenMesh REQUIRED)

# Include directories for FreeGLUT, OpenGL, and OpenMesh
include_directories(${FreeGLUT_INCLUDE_DIRS})
include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${OpenMesh_INCLUDE_DIRS})
message(STATUS "OpenMesh_INCLUDE_DIRS: ${OPENGL_INCLUDE_DIR}")
message(STATUS "OpenMesh_INCLUDE_DIRS: ${OPENMESH_INCLUDE_DIRS}")

# collect sources
file(GLOB all_sources src/*.cpp)
file(GLOB all_ann_sources ANN/*.cpp)
file(GLOB all_ann_headers ANN/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add executable target 
add_executable(assign5 ${all_sources})
target_include_directories(assign5 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_library(ann ${all_ann_sources} ${all_ann_headers})

# Link libraries to the executable 
target_link_libraries(assign5
    -lglut
    OpenMeshCore
    OpenMeshTools
    ${OPENGL_LIBRARIES}
)
target_link_libraries(assign5 optimized  ann)

