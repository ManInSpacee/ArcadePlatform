#include "Paddle.hpp"

void Paddle::Draw() {
    DrawRectangleRounded({x, y, width, height}, 0.8, 0, {43, 51, 24, 255});
}

void Paddle::LimitMovement() {
    int screen_height = GetScreenHeight();
    if (y <= 0) y = 0;
    if (y + height >= screen_height) y = screen_height - height;
}

void Paddle::Update() {
    if (IsKeyDown(KEY_UP)) y -= speed;
    if (IsKeyDown(KEY_DOWN)) y += speed;
    LimitMovement();
}

void CpuPaddle::Update(int ball_y) {
    if (y + height / 2 > ball_y) y -= speed;
    if (y + height / 2 <= ball_y) y += speed;
    LimitMovement();
}
