project(assignment7)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")
endif()

# setup output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# additional CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# setup FreeGLUT
find_package(FreeGLUT)
include_directories(${FREEGLUT_INCLUDE_DIR})
if(NOT FREEGLUT_FOUND)
    message(ERROR " FREEGLUT not found")
endif()


# setup OpenGL
find_package(OpenGL)
include_directories(${OpenGL_INCLUDE_DIRS})
if(NOT OPENGL_FOUND)
    message(ERROR " OpenGL not found")
endif()

# setup OpenMesh
find_package(OpenMesh)
include_directories(${OPENMESH_INCLUDE_DIRS})
if(NOT OPENMESH_FOUND)
    message(ERROR " OpenMesh not found")
endif()
set_property(
    DIRECTORY
    APPEND PROPERTY COMPILE_DEFINITIONS _USE_MATH_DEFINES
)

# collect sources
file(GLOB viewer_sources viewer/*.cpp)
file(GLOB viewer_headers viewer/*.h)

file(GLOB decimation_sources decimation/*.cpp)
file(GLOB decimation_headers decimation/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# compile and link
add_executable(decimation ${decimation_sources} ${decimation_headers})
add_executable(viewer ${viewer_sources} ${viewer_headers})

target_link_libraries(viewer debug ${OPENMESH_CORE_DEBUG_LIBRARY} debug ${OPENMESH_TOOLS_DEBUG_LIBRARY} optimized ${OPENMESH_CORE_LIBRARY} optimized  ${OPENMESH_TOOLS_LIBRARY} ${OPENGL_LIBRARIES}  ${FREEGLUT_LIBRARY} )
target_link_libraries(decimation debug ${OPENMESH_CORE_DEBUG_LIBRARY} debug ${OPENMESH_TOOLS_DEBUG_LIBRARY} optimized ${OPENMESH_CORE_LIBRARY} optimized  ${OPENMESH_TOOLS_LIBRARY})
