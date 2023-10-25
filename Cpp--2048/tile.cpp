#include <iostream>
#include "Tile.hpp"

std::vector<Tile*> Tile::tileList = {};

Tile::Tile(int value, int coord[])
{
    this->value = value;
    this->coord[0] = coord[0];
    this->coord[1] = coord[1];

    tileList.push_back(this);
}

Tile::~Tile()
{
    std::cout << " TILE WAS PURGED\n";
}

void Tile::doubleValue()
{
    this->value *= 2;
}

void Tile::peek()
{
    for (auto i : tileList)
    {
        std::cout << i << ", " << i->value << ", [" << i->coord[0] << "," << i->coord[1] << "]\n";
    }
}
