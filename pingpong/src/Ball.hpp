#pragma once
#include "raylib.h"

extern int player_score;
extern int cpu_score;

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw();
    void Update();
    void ResetBall();
};
