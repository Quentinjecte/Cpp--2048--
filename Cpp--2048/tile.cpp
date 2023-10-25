#include <iostream>
#include "tile.hpp"

Tile::Tile(int value, int coord[])
{
    this->value = value;
    this->coord[0] = coord[0];
    this->coord[1] = coord[1];
}

Tile::~Tile()
{
    std::cout << " TILE WAS PURGED\n";
}

void Tile::doubleValue()
{
    this->value *= 2;
}
