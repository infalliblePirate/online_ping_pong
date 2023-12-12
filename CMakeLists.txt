cmake_minimum_required(VERSION 3.26)
project(client)

set(CMAKE_CXX_STANDARD 17)

add_executable(client main.cpp
        network.h
        network.cpp
        player.h
        player.cpp
        sfml/window.h
        sfml/window.cpp
        sfml/input.h
        sfml/input.cpp
        sfml/ball.h
        sfml/ball.cpp)

target_link_libraries(client -L/usr/lib/x86_64-linux-gnu -lenet
sfml-graphics sfml-window sfml-system sfml-audio)
