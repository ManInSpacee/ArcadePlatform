#include "raylib.h"
#include "grid.h"

void RunTetrisGame()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "TetrisGame");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 2;
    grid.grid[8][7] = 3;
    grid.Print();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        EndDrawing();
    }
}