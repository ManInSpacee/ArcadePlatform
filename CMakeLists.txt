cmake_minimum_required(VERSION 3.30)
project(ArcadePlatform)

include_directories(External)
include_directories(src)
include_directories(snake/src)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# Загрузка и сборка Raylib (если не установлен)
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

# Основные файлы платформы
set(PLATFORM_SRC
    src/main.cpp
    src/Platform.cpp
    src/Platform.h
    src/GameRunners.cpp
)

# Файлы игры Snake
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


set(TETRIS_SRC
        tetris/src/TetrisGameRunner.cpp
        tetris/src/Grid.cpp
        tetris/src/Grid.h
        tetris/src/Block.cpp
        tetris/src/Block.h
        tetris/src/Position.cpp
        tetris/src/Position.h
        tetris/src/Colors.h
        tetris/src/Colors.cpp
        tetris/src/Blocks.cpp
        tetris/src/Game.cpp
        tetris/src/Game.h
)
# set(MINESWEEPER_SRC
#     tetris/src/...
# )

# Собираем все в один исполняемый файл
add_executable(${PROJECT_NAME}
    ${PLATFORM_SRC}
    ${SNAKE_SRC}
    ${TETRIS_SRC}
)

# Подключение Raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Копирование ресурсов (если есть)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/snake/Sounds)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/snake/Sounds DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/snake/Graphics)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/snake/Graphics DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

