cmake_minimum_required(VERSION 3.21)
project(Pong)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/libs)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)



add_executable(Pong src/main.cpp
                    src/Ball.cpp
                    src/Pong.cpp)

target_compile_options(Pong PRIVATE
  -Wall
  -Wextra
  -Werror
  -Wpedantic
)


target_include_directories(
  Pong
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(Pong SYSTEM PRIVATE ${raylib_SOURCE_DIR}/src)

target_link_libraries(
  Pong PRIVATE raylib
)

set_target_properties(Pong PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
