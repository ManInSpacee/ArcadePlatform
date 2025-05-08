#pragma once
#include "Grid.h"
#include "Blocks.cpp"

namespace TetrisGame {
    class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;
        Music music;
    private:
        void LockBlock();
        void MoveBlockLeft();
        void MoveBlockRight();
        void RotateBlock();
        void Reset();
        void UpdateScore(int LinesCleared, int moveDownPoints);
        bool isBlockOutside();
        bool BlockFits();
        std::vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
        Sound rotateSound;
        Sound clearSound;

    };
}

