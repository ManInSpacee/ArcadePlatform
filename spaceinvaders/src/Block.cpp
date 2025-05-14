#include "Block.hpp"

Block::Block(Vector2 position) {
    this->position = position;
}

void Block::Draw() {
    DrawRectangle((int)position.x, (int)position.y, 3, 3, {243, 216, 63, 255});
}
