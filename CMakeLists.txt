cmake_minimum_required(VERSION 2.8)
project(engine-cpp)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(src)
