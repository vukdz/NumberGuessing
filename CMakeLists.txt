cmake_minimum_required(VERSION 3.10)

project(NumberGuessing CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
    src/main.cpp
    src/Game.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(NumberGuessing ${SOURCE_FILES})

set_target_properties(NumberGuessing PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "&{CMAKE_BINARY_DIR}/bin"
)