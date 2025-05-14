#include <iostream>

#include "raylib.h"
#include "Game.h"
#include "Colors.h"


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
    if (IsWindowReady())
    {
        CloseWindow();
    }
    InitWindow(600, 820, "TetrisGame");
    SetTargetFPS(60);

    Font font = LoadFontEx("../tetris/Font/monogram.ttf", 64, 0, 0);

    TetrisGame::Game game; // Создаём ОДИН объект с указанием пространства имён

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(interval))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {465, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {465, 215}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {420, 515}, 38, 2, WHITE);
            ClearBackground(faintBlue);
        }
        DrawRectangleRounded({420, 75, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 32, 2);

        DrawTextEx(font, scoreText, {420 + (170 - textSize.x)/2, 80}, 38, 2, WHITE);
        DrawRectangleRounded({420, 275, 170, 180}, 0.15, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}