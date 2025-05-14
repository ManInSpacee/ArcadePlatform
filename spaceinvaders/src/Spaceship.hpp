#pragma once
#include "raylib.h"
#include "Laser.hpp"
#include <vector>

class Spaceship {
public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void Update();
    void MoveRight();
    void MoveLeft();
    void FireLaser();
    std::vector<Laser> lasers;
private:
    Texture2D image;
    Vector2 position;
    double lastFireTime;
    };


