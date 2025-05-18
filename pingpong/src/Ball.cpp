#include "Ball.hpp"

void Ball::Draw() {
    DrawCircle(x, y, radius, {43, 51, 24, 255});
}

void Ball::Update() {
    x += speed_x;
    y += speed_y;

    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();

    if (y + radius >= screen_height || y - radius <= 0) {
        speed_y *= -1;
    }

    if (x + radius >= screen_width) {
        cpu_score++;
        ResetBall();
    }

    if (x - radius <= 0) {
        player_score++;
        ResetBall();
    }
}

void Ball::ResetBall() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int dir[2] = {-1, 1};
    speed_x *= dir[GetRandomValue(0, 1)];
    speed_y *= dir[GetRandomValue(0, 1)];
}
