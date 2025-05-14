#include "raylib.h"
#include "Game.hpp"
#include "Obstacle.hpp"
#include <iostream>

void RunSpaceInvadersGame()
{
    if (IsWindowReady())
    {
        CloseWindow();
    }

    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(60);

    if (!IsWindowReady()) {
        std::cerr << "Error: Window initialization failed." << std::endl;
        return;
    }

    Game game;

    while (!WindowShouldClose())
    {
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}