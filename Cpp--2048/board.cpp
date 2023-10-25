#include <iostream>
#include "board.hpp"

Board::Board(int size[])
{
    this->size[0] = size[0];
    this->size[1] = size[1];
}

Board::~Board()
{
    std::cout << "BOARD WAS PURGED\n";
}

void Board::spawnTiles()
{
    std::cout << "There is no void board::spawnTiles()\nThe devs are lazy :p\n";
}