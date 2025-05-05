#pragma once
#include <vector>
#include <map>

#include "Colors.h"
#include "position.h"
class Block
{
public:
    Block();
    void Draw();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();

    void UndoRotation();

    int id;
    std::map<int, std::vector<Position>> cells;
private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};


