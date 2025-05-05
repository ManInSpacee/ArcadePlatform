#include "raylib.h"
#include "Game.h"

double lastUpdatedTime = 0;
double interval = 0.2;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdatedTime >= interval)
    {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}

void RunTetrisGame()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(400, 800, "TetrisGame");
    SetTargetFPS(60);

    TetrisGame::Game game; // Создаём ОДИН объект с указанием пространства имён

    while (!WindowShouldClose())
    {
        game.HandleInput();
        if (EventTriggered(interval))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}