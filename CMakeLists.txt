cmake_minimum_required(VERSION 4.3)
project(RayLibTest_Sept24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimize FetchContent: Don't build Raylib's built-in examples or extra tools
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
        raylib #the name of the project in CMakeLists.txt for the repo in the link below
        GIT_REPOSITORY https://github.com/raysan5/raylib
        GIT_TAG 6.0 #tag from April 22, 2026
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(RayLibTest_Sept24 main.cpp
        Maze.cpp
        Maze.h)

target_link_libraries(
        RayLibTest_Sept24 #target
        PRIVATE raylib #item
)
