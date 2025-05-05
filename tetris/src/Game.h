#pragma once
#include "Grid.h"
#include "Blocks.cpp"

namespace TetrisGame {
    class Game {
    public:
        Game();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void LockBlock();
        void MoveBlockDown();
        bool gameOver;
    private:
        void RotateBlock();
        void Reset();
        bool isBlockOutside();
        bool BlockFits();
        std::vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;

    };
}

