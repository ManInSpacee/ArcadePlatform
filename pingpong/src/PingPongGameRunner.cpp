#include "raylib.h"
#include "Ball.hpp"
#include "Paddle.hpp"

Color Green = {173, 204, 96, 255};
Color Dark_Green = {163, 194, 86, 255};
Color Light_Green = {173, 204, 96, 255};


int player_score = 0;
int cpu_score = 0;

Ball ball;
Paddle player;
CpuPaddle cpu;

void RunPingPongGame() {


    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "PING PONG");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Update
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        // Collision
        if (CheckCollisionCircleRec({ball.x, ball.y}, ball.radius, {player.x, player.y, player.width, player.height})) {
            ball.speed_x *= -1;
        }

        if (CheckCollisionCircleRec({ball.x, ball.y}, ball.radius, {cpu.x, cpu.y, cpu.width, cpu.height})) {
            ball.speed_x *= -1;
        }

        // Draw
        ClearBackground(Dark_Green);
        DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
        DrawCircle(screen_width / 2, screen_height / 2, 150, {153, 184, 76, 255});
        // DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, {43, 51, 1, 55});

        ball.Draw();
        cpu.Draw();
        player.Draw();

        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, {43, 51, 24, 255});
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, {43, 51, 24, 255});

        EndDrawing();
    }

    CloseWindow();
}
