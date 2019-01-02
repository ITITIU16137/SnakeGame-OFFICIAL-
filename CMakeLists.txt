cmake_minimum_required(VERSION 3.13)
project(Snake_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(SnakeGame)

add_executable(Snake_Game
        SnakeGame/bin/Debug/SnakeGame.exe
        SnakeGame/obj/Debug/EndScreen.o
        SnakeGame/obj/Debug/main.o
        SnakeGame/obj/Debug/menuStart.o
        SnakeGame/obj/Debug/setConsole.o
        SnakeGame/obj/Debug/Sound.o
        SnakeGame/a.wav
        SnakeGame/b.wav
        SnakeGame/c.wav
        SnakeGame/EndScreen.cpp
        SnakeGame/EndScreen.h
        SnakeGame/main.cpp
        SnakeGame/main.o
        SnakeGame/menuStart.cpp
        SnakeGame/menuStart.h
        SnakeGame/setConsole.cpp
        SnakeGame/setConsole.h
        SnakeGame/SnakeGame.cbp
        SnakeGame/SnakeGame.depend
        SnakeGame/SnakeGame.layout
        SnakeGame/Sound.cpp
        SnakeGame/Sound.h
        LICENSE
        README.md)
