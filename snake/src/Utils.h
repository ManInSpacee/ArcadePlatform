#pragma once
#include "raylib.h"
#include <deque>

extern const Color lightGreen;
extern const Color darkGreen;
extern const int cellSize;
extern const int cellCount;
extern const int offset;

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
bool eventTriggered(double interval);