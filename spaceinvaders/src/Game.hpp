#pragma once
#include "Spaceship.hpp"
#include "Obstacle.hpp"
#include "raylib.h"

class Game {
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
private:
    void DeleteInactiveLasers();
    std::vector<Obstacle> CreateObstacles();
    Spaceship spaceship;
    std::vector<Obstacle> obstacles;
};


