cmake_minimum_required(VERSION 2.8)

project(gbaEmu)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(gbaemu ${SRC})

target_include_directories(gbaemu PUBLIC include/)

target_link_libraries(gbaemu SDL2)