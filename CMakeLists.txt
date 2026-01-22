cmake_minimum_required(VERSION 3.23)
project(RAYTRACER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RAYTRACER
    src/main.cpp
    src/VECH3_H.hpp
    src/color.h
)

target_include_directories(RAYTRACER
    PRIVATE
        src
)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(RAYTRACER PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
