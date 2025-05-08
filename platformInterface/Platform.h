#pragma once
#include "raylib.h"

enum class GamePlatform {
    NONE,
    SNAKE,
    TETRIS,
    SPACEINVADERS
};

class Platform {
public:
    void Run();
private:
    GamePlatform currentGame = GamePlatform::NONE;
    void ShowMenu();
    void RunGame(GamePlatform game);
};