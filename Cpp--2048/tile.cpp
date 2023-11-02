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
    std::cout << value << " Valeur "
        << "[" << coord[0] << coord[1] << "]"
        << " Coord \n";
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

// Private complex data editors
void TileSet::mfUp() {
    // Iterate through each column
    for (int col = 0; col < tiles[0].size(); col++) {
        // Perform fusion
        for (int row = 1; row < tiles.size(); row++) {
            if (tiles[row][col] != 0) {
                for (int aboveRow = row - 1; aboveRow >= 0; aboveRow--) {
                    if (tiles[aboveRow][col] == tiles[row][col]) {
                        // Merge the tiles
                        tiles[aboveRow][col] *= 2;
                        tiles[row][col] = 0;
                        break; // Stop checking higher tiles for this tile
                    }
                    else if (tiles[aboveRow][col] != 0) {
                        // There is a non-zero tile above, so stop checking
                        break;
                    }
                }
            }
        }

        // Perform tile movement
        for (int row = 1; row < tiles.size(); row++) {
            if (tiles[row][col] != 0) {
                int currentRow = row;
                while (currentRow > 0 && tiles[currentRow - 1][col] == 0) {
                    // Move the tile upward by swapping values
                    tiles[currentRow - 1][col] = tiles[currentRow][col];
                    tiles[currentRow][col] = 0;
                    currentRow--;
                }
            }
        }
    }
}

void TileSet::mfDown() {
    // Iterate through each column
    for (int col = 0; col < tiles[0].size(); col++) {
        // Perform fusion
        for (int row = tiles.size() - 2; row >= 0; row--) {
            if (tiles[row][col] != 0) {
                for (int belowRow = row + 1; belowRow < tiles.size(); belowRow++) {
                    if (tiles[belowRow][col] == tiles[row][col]) {
                        // Merge the tiles
                        tiles[belowRow][col] *= 2;
                        tiles[row][col] = 0;
                        break; // Stop checking lower tiles for this tile
                    }
                    else if (tiles[belowRow][col] != 0) {
                        // There is a non-zero tile below, so stop checking
                        break;
                    }
                }
            }
        }

        // Perform tile movement
        for (int row = tiles.size() - 2; row >= 0; row--) {
            if (tiles[row][col] != 0) {
                int currentRow = row;
                while (currentRow < tiles.size() - 1 && tiles[currentRow + 1][col] == 0) {
                    // Move the tile downward by swapping values
                    tiles[currentRow + 1][col] = tiles[currentRow][col];
                    tiles[currentRow][col] = 0;
                    currentRow++;
                }
            }
        }
    }
}

void TileSet::mfLeft() {
    // Iterate through each row
    for (int row = 0; row < tiles.size(); row++) {
        // Perform fusion
        for (int col = 1; col < tiles[0].size(); col++) {
            if (tiles[row][col] != 0) {
                for (int leftCol = col - 1; leftCol >= 0; leftCol--) {
                    if (tiles[row][leftCol] == tiles[row][col]) {
                        // Merge the tiles
                        tiles[row][leftCol] *= 2;
                        tiles[row][col] = 0;
                        break; // Stop checking tiles to the left for this tile
                    }
                    else if (tiles[row][leftCol] != 0) {
                        // There is a non-zero tile to the left, so stop checking
                        break;
                    }
                }
            }
        }

        // Perform tile movement
        for (int col = 1; col < tiles[0].size(); col++) {
            if (tiles[row][col] != 0) {
                int currentCol = col;
                while (currentCol > 0 && tiles[row][currentCol - 1] == 0) {
                    // Move the tile to the left by swapping values
                    tiles[row][currentCol - 1] = tiles[row][currentCol];
                    tiles[row][currentCol] = 0;
                    currentCol--;
                }
            }
        }
    }
}

void TileSet::mfRight() {
    // Iterate through each row
    for (int row = 0; row < tiles.size(); row++) {
        // Perform fusion
        for (int col = tiles[0].size() - 2; col >= 0; col--) {
            if (tiles[row][col] != 0) {
                for (int rightCol = col + 1; rightCol < tiles[0].size(); rightCol++) {
                    if (tiles[row][rightCol] == tiles[row][col]) {
                        // Merge the tiles
                        tiles[row][rightCol] *= 2;
                        tiles[row][col] = 0;
                        break; // Stop checking tiles to the right for this tile
                    }
                    else if (tiles[row][rightCol] != 0) {
                        // There is a non-zero tile to the right, so stop checking
                        break;
                    }
                }
            }
        }

        // Perform tile movement
        for (int col = tiles[0].size() - 2; col >= 0; col--) {
            if (tiles[row][col] != 0) {
                int currentCol = col;
                while (currentCol < tiles[0].size() - 1 && tiles[row][currentCol + 1] == 0) {
                    // Move the tile to the right by swapping values
                    tiles[row][currentCol + 1] = tiles[row][currentCol];
                    tiles[row][currentCol] = 0;
                    currentCol++;
                }
            }
        }
    }
}
