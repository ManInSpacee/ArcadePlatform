cmake_minimum_required(VERSION 3.21)
project(ArcadePlatform)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Raylib
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)

if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
endif()

include_directories(
        External
        platformInterface
        snake/src
        tetris/src
        spaceinvaders/src
)

# Platform
set(PLATFORM_SRC
        platformInterface/main.cpp
        platformInterface/Platform.cpp
        platformInterface/Platform.h
)

# Snake
set(SNAKE_SRC
        snake/src/Utils.cpp
        snake/src/Utils.h
        snake/src/Snake.cpp
        snake/src/Snake.h
        snake/src/Food.cpp
        snake/src/Food.h
        snake/src/Game.cpp
        snake/src/Game.h
        snake/src/SnakeGameRunner.cpp
)

# Tetris
set(TETRIS_SRC
        tetris/src/TetrisGameRunner.cpp
        tetris/src/Grid.cpp
        tetris/src/Grid.h
        tetris/src/Block.cpp
        tetris/src/Block.h
        tetris/src/Position.cpp
        tetris/src/Position.h
        tetris/src/Colors.cpp
        tetris/src/Colors.h
        tetris/src/Blocks.cpp
        tetris/src/Game.cpp
        tetris/src/Game.h
)

# PING PONG
set(PINGPONG_SRC
        pingpong/src/PingPongGameRunner.cpp
        pingpong/src/Ball.cpp
        pingpong/src/Ball.hpp
        pingpong/src/Paddle.cpp
        pingpong/src/Paddle.hpp
)


set(RESOURCES
        snake/Sounds/eat.wav
        snake/Sounds/hit.wav
)

add_executable(${PROJECT_NAME}
        ${PLATFORM_SRC}
        ${SNAKE_SRC}
        ${TETRIS_SRC}
        ${PINGPONG_SRC}
)

target_link_libraries(${PROJECT_NAME} raylib)
