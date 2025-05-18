#include "Game.h"
#include "Utils.h"
#include "raylib.h"

void RunSnakeGame() {
    if (IsWindowReady())
        {
        CloseWindow();
    }

    InitWindow(offset*2 + cellSize*cellCount, offset*2 + cellSize*cellCount, "Snake Game");
    SetTargetFPS(60);
    float speed = 0.1f;

    SnakeGame::Game game; // Создаём ОДИН объект с указанием пространства имён

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (eventTriggered(speed)) {
            game.Update();
        }

        // Input handling
        game.HandleInput();

        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }

        // Drawing
        ClearBackground(lightGreen);
        DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset-5,
            (float)cellSize*cellCount+10, (float)cellSize*cellCount+10}, 5, DARKGREEN);
        DrawText("Snake Game", offset + 5, 20, 40, DARKGREEN);
        DrawText(TextFormat("SCORE: %i", game.score), 630, 20, 40, DARKGREEN);
        DrawText("Press ESC to return to menu", offset + 10, offset + cellSize*cellCount + 30, 20, DARKGREEN);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    ShowMenu();
}