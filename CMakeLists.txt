cmake_minimum_required(VERSION 3.5)

project(triangle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Window.cpp
    ExampleWindow.cpp
    )
set(HEADERS
    Window.h
    ExampleWindow.h
    )
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(triangle${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(triangle main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(triangle ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
