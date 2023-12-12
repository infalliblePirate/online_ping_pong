cmake_minimum_required(VERSION 3.26)
project(server)

set(CMAKE_CXX_STANDARD 17)

add_executable(server main.cpp
        network.h
        network.cpp)

target_link_libraries(server -L/usr/lib/x86_64-linux-gnu -lenet)
