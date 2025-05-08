#include "Platform.h"

// Заглушка для Tetris
// void RunTetrisGame() {
//     if (IsWindowReady()) {
//         CloseWindow();
//     }
//
//     InitWindow(800, 600, "Tetris Game");
//     SetTargetFPS(60);
//
//     while (!WindowShouldClose()) {
//         if (IsKeyPressed(KEY_ESCAPE)) {
//             break;
//         }
//
//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//
//         DrawText("Tetris Game", 250, 200, 40, DARKGRAY);
//         DrawText("Coming Soond..", 320, 300, 30, GRAY);
//
//         EndDrawing();
//     }
//
//     CloseWindow();
// }

// Заглушка для Space Invaders
void RunSpaceInvadersGame() {
    if (IsWindowReady()) {
        CloseWindow();
    }
    
    InitWindow(800, 600, "Space Invaders Game");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Space Invaders Game", 250, 200, 40, DARKGRAY);
        DrawText("Coming Soon...", 320, 300, 30, GRAY);
        
        EndDrawing();
    }
    
    CloseWindow();
}
