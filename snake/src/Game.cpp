#include "Game.h"

namespace SnakeGame {
    Game::Game() : food(snake.body) {
        InitAudioDevice();
        eatSound = LoadSound("../snake/Sounds/eat.wav");
        hitSound = LoadSound("../snake/Sounds/hit.wav");
    }

    Game::~Game() {
        UnloadSound(eatSound);
        CloseAudioDevice();
    }

    void Game::Draw() {
        food.Draw();
        snake.Draw();
    }

    void Game::Update() {
        if (running) {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
    }

    void Game::CheckCollisionWithFood() {
        if (Vector2Equals(snake.body[0], food.position)) {
            food.position = food.GenerateRandomPos(snake.body);
            snake.addSegment = true;
            score++;
            SetSoundVolume(eatSound, 0.2f);
            PlaySound(eatSound);
        }
    }

    void Game::CheckCollisionWithEdges() {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
            GameOver();
        }
    }

    void Game::CheckCollisionWithTail() {
        std::deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (ElementInDeque(snake.body[0], headlessBody)) {
            GameOver();
        }
    }

    void Game::GameOver() {
        PlaySound(hitSound);
        snake.Reset();
        food.position = food.GenerateRandomPos(snake.body);
        running = false;
        score = 0;
    }
}