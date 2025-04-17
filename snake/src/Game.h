#pragma once
#include "Snake.h"
#include "Food.h"

class Game {
public:
    Snake snake;
    Food food;
    bool running = true;
    int score = 0;
    Sound eatSound;
    Sound hitSound;

    Game();
    ~Game();

    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();
};