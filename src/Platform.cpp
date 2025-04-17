#include "Platform.h"
#include <vector>

struct Button {
    Rectangle rect;
    const char* text;
    Color color;
    Color hoverColor;
    GamePlatform game;
};

// Константы
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Arcade Platform";

extern void RunSnakeGame();
extern void RunArkanoidGame();
extern void RunMinesweeperGame();

void Platform::Run() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        if (currentGame == GamePlatform::NONE) {
            ShowMenu();
        } else {
            RunGame(currentGame);
            currentGame = GamePlatform::NONE;
        }
    }
    
    CloseWindow();
}

void Platform::ShowMenu() {
    std::vector<Button> buttons;
    buttons.push_back({ {SCREEN_WIDTH/2 - 150, 150, 300, 60}, "Snake", DARKGREEN, GREEN, GamePlatform::SNAKE });
    buttons.push_back({ {SCREEN_WIDTH/2 - 150, 250, 300, 60}, "Arkanoid", DARKGREEN, GREEN, GamePlatform::ARKANOID });
    buttons.push_back({ {SCREEN_WIDTH/2 - 150, 350, 300, 60}, "Minesweeper", DARKGREEN, GREEN, GamePlatform::MINESWEEPER });
    buttons.push_back({ {SCREEN_WIDTH/2 - 150, 450, 300, 60}, "Exit", RED, MAROON, GamePlatform::NONE });

    while (!WindowShouldClose() && currentGame == GamePlatform::NONE) {
        for (auto& btn : buttons) {
            bool isHovered = CheckCollisionPointRec(GetMousePosition(), btn.rect);
            
            if (isHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (btn.game == GamePlatform::NONE) { // Кнопка Exit
                    CloseWindow();
                    return;
                } else {
                    currentGame = btn.game;
                    break;
                }
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("ARCADE PLATFORM", SCREEN_WIDTH/2 - 200, 50, 40, DARKGRAY);


        for (auto& btn : buttons) {
            bool isHovered = CheckCollisionPointRec(GetMousePosition(), btn.rect);
            DrawRectangleRec(btn.rect, isHovered ? btn.hoverColor : btn.color);


            int textWidth = MeasureText(btn.text, 24);
            int textX = btn.rect.x + (btn.rect.width - textWidth) / 2;
            DrawText(btn.text, textX, btn.rect.y + 15, 24, WHITE);
        }

        EndDrawing();
    }
}

void Platform::RunGame(GamePlatform game) {
    switch (game) {
        case GamePlatform::SNAKE:
            RunSnakeGame();
            break;
        case GamePlatform::ARKANOID:
            RunArkanoidGame();
            break;
        case GamePlatform::MINESWEEPER:
            RunMinesweeperGame();
            break;
        default:
            break;
    }
}