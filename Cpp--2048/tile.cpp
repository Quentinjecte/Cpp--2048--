#include <iostream>
#include "./tile.hpp"

std::vector<std::vector<int>> tiles = {};

// Constructors and Destructors
TileSet::TileSet(int size[])
{
    // Created a temporary, dynamically allocated vector (since size can vary) to copy into the class' own vector
    std::vector<std::vector<int>> tempVec(size[0], std::vector<int>(size[1], 0));
    this->tiles = tempVec;
}

TileSet::~TileSet()
{
    std::cout << "TILESET WAS PURGED\n";
}

// Getters
int TileSet::getTile(int coord[2])
{
    return this->tiles[coord[0]][coord[1]];
}

// Setters
void TileSet::setTile(int value, int coord[2])
{
    this->tiles[coord[0]][coord[1]] = value;
    std::cout << value << " Valeur " << "[" << coord[0] << coord[1] << "]" << " Coord \n";
}

// "Journalists"
bool TileSet::valueScan(int value)
{
    // Increment x as the "row" part of tiles' coordinates
    for (int x = 0; x < this->tiles.size(); x++)
    {
        // Increment y as the "col" part of tiles' coordinates
        for (int y = 0; y < this->tiles[x].size(); y++)
        {
            if (tiles[x][y] == value)
            {
                return true;
            }
        }
    }

    return false;
}

bool TileSet::isFull()
{
    // Increment x as the "row" part of tiles' coordinates
    for (int x = 0; x < this->tiles.size(); x++)
    {
        // Increment y as the "col" part of tiles' coordinates
        for (int y = 0; y < this->tiles[x].size(); y++)
        {
            if (tiles[x][y] == 0)
            {
                return false;
            }
        }
    }

    return true;
}