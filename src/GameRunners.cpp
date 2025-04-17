#include "Platform.h"


void RunArkanoidGame() {
    if (IsWindowReady()) {
        CloseWindow();
    }
    
    InitWindow(800, 600, "Arkanoid Game");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        // Выход в меню при нажатии ESC
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Arkanoid Game", 250, 200, 40, DARKGRAY);
        DrawText("Coming Soon...", 280, 300, 30, GRAY);
        
        EndDrawing();
    }
    
    CloseWindow();
}


void RunMinesweeperGame() {
    if (IsWindowReady()) {
        CloseWindow();
    }
    
    InitWindow(800, 600, "Minesweeper Game");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Minesweeper Game", 250, 200, 40, DARKGRAY);
        DrawText("Coming Soon...", 320, 300, 30, GRAY);
        
        EndDrawing();
    }
    
    CloseWindow();
} 