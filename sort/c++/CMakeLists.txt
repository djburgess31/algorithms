cmake_minimum_required(VERSION 3.18)
project(c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(c__ main.cpp sorts.hpp sorts.cpp)

target_link_libraries(c__ SDL2)
