#include <iostream>
#include <ctime>
#include <random>
#include "./tile.hpp"
#include "./board.hpp"

#define CTL (char)218 // ┌
#define CTR (char)191 // ┐
#define CBL (char)192 // └
#define CBR (char)217 // ┘
#define IPD (char)194 // ┬
#define IPU (char)193 // ┴
#define IPR (char)195 // ├
#define IPL (char)180 // ┤
#define SLV (char)179 // │
#define SLH (char)196 // ─
#define ICR (char)197 // ┼

// Constructor
Board::Board(int size[], TileSet* tileSetPtr)
{
    // Seeds for tile generation later ;3
    srand(time(NULL));

    this->width = size[0];
    this->height = size[1];
    this->tileSet = tileSetPtr;
}

// Destructor
Board::~Board()
{
    std::cout << "BOARD WAS PURGED\n";
}

/** \brief
 * Generates a tile in the TileSet at random
 * If it attempt to generate on a not-empty tile, loops back and tries again
 */
void Board::spawnTiles()
{

    bool success = false;
    int targetCoord[2];

    // Loops until it successfully generated a tile
    while (!success)
    {
        // Picks a tile at random
        targetCoord[0] = (rand() % width);
        targetCoord[1] = (rand() % height);

        // Check if the target is a free space
        if (this->tileSet->getTile(targetCoord) == 0)
        {
            // Generates a tile between 2(70% of the time) and 4(30% of the time)
            if (St != 1)
            {
                for (int i = 0; i < 2; i++)
                {
                    srand(time(NULL));

                    if (rand() % 100 < 70)
                    {
                        this->tileSet->setTile(2, targetCoord);
                    }
                    else
                    {
                        this->tileSet->setTile(4, targetCoord);
                    }
                }
                St -= 1;
            }
            else
            {
                if (rand() % 100 < 70)
                {
                    this->tileSet->setTile(2, targetCoord);
                }
                else
                {
                    this->tileSet->setTile(4, targetCoord);
                }
            }

            success = true;
        }
    }
}

/** \brief
 * Board drawing function
 * Can adapt to any size board
 * If there is data that would render outside of the board, they will not cause an issue, instead they'll never be read
 */

void Board::drawBoard()
{
    // Drawing top of board
    std::cout << CTL << SLH;
    for (int w = 0; w < this->width - 1; w++)
    {
        std::cout << IPD << SLH;
    }
    std::cout << CTR << "\n";

    // Drawing tiles and spacers
    int targetCoord[2];
    for (int x = 0; x < this->height; x++)
    {
        std::cout << SLV;
        for (int y = 0; y < this->width; y++)
        {
            // Updates the targeted tile to show, and associate its value with a letter
            targetCoord[0] = x;
            targetCoord[1] = y;
            switch (this->tileSet->getTile(targetCoord))
            {
            case 2:
                std::cout << 'A' << SLV;
                break;
            case 4:
                std::cout << 'B' << SLV;
                break;
            case 8:
                std::cout << 'C' << SLV;
                break;
            case 16:
                std::cout << 'D' << SLV;
                break;
            case 32:
                std::cout << 'E' << SLV;
                break;
            case 64:
                std::cout << 'F' << SLV;
                break;
            case 128:
                std::cout << 'G' << SLV;
                break;
            case 256:
                std::cout << 'H' << SLV;
                break;
            case 512:
                std::cout << 'I' << SLV;
                break;
            case 1024:
                std::cout << 'J' << SLV;
                break;
            case 2048:
                std::cout << 'K' << SLV;
                break;
            default:
                std::cout << ' ' << SLV;
                break;
            }
        }
        std::cout << "\n";

        // Drawing spacers
        if (x < this->height - 1)
        {
            std::cout << IPR << SLH;
            for (int w = 0; w < width - 1; w++)
            {
                std::cout << ICR << SLH;
            }
            std::cout << IPL << "\n";
        }
    }

    // Drawing bottom of board
    std::cout << CBL << SLH;
    for (int w = 0; w < this->width - 1; w++)
    {
        std::cout << IPU << SLH;
    }
    std::cout << CBR << "\n";
}

/** \brief
 * Check condition for losing the game
 * This function isn't in main() since it needs access to the private data of the Tile class
 * Board is the friend of Tile
 *
 * \return Boolean used in main to update the gameOver variable
 */
bool Board::chkLoss()
{
    int targetCoord[2];
    int targetNeighbor[2];

    // Only tests for defeat if the TileSet has no more empty spaces
    if (this->tileSet->isFull())
    {
        // Skirms through every tiles except for the bottom-most row and the left-most col
        for (int x = 0; x < this->width - 1; x++)
        {
            for (int y = 0; y < this->height - 1; y++)
            {
                // Updates the targeted tile for the following test
                targetCoord[0] = x;
                targetCoord[1] = y;

                // Updates the neighbor tile coordinates for testing
                targetNeighbor[0] = targetCoord[0];
                targetNeighbor[0] = +1;

                // Tests both the bottom and left neighbors
                if (this->tileSet->getTile(targetCoord) == this->tileSet->getTile(targetNeighbor))
                {
                    return false;
                }
            }
        }
    }
}

/** \brief
 * Check condition for wining the game
 * This function isn't in main() since it needs access to the private data of the Tile class
 * Board is the friend of Tile
 *
 * \return Boolean used in main() to update the gameOver variable
 */
bool Board::chkWin()
{
    if (this->tileSet->valueScan(2048))
    {
        return true;
    }
}


/** \brief
 * Moves and fuses the tiles within the TileSet
 * Adapts depending on the direction of the input, going through the farther tiles, and moving them line by line towards the "wall"
 */

