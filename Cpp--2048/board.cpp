#include <iostream>
#include "Board.hpp"
#include "Tile.hpp"

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


Board::Board(int size[])
{
    this->width = size[0];
    this->height = size[1];
}

Board::~Board()
{
    std::cout << "BOARD WAS PURGED\n";
}

void Board::spawnTiles()
{
    std::cout << "There is no void board::spawnTiles()\nThe devs are lazy :p\n";

}

void Board::drawBoard()
{
    // Drawing top of board
    std::cout << CTL << SLH;
    for (int w = 0; w < width - 1; w++)
    {
        std::cout << IPD << SLH;
    }
    std::cout << CTR << "\n";


    bool dataPrinted = false;                                       // Used to stop the while loop after a print for the tile place
    std::vector<Tile*>::const_iterator it = Tile::tileList.begin(); // Used in the while loop to access but not edit the Tiles' data

    // Drawing tiles and spacers
    for (int h = 0; h < height; h++)
    {
        std::cout << SLV;
        for (int w = 0; w < width; w++)
        {
            while (!dataPrinted && it != Tile::tileList.end()) // Scours the vector for every existing tiles
            {
                if ((*it)->coord[0] == h + 1 && (*it)->coord[1] == w + 1) // Check if coordinates of tile matches
                {
                    // TODO : Replace with a switch case to print letters instead of values
                    switch ((*it)->value)
                    {
                    case 2:
                        std::cout << "A" << SLV;
                        break;
                    case 4:
                        std::cout << "B" << SLV;
                        break;
                    }
                    dataPrinted = true;
                }
                else { ++it; }
            }
            if (!dataPrinted) { std::cout << ' ' << SLV; } // Prints a blank space if no match was found in the previous while loop
            it = Tile::tileList.begin();
            dataPrinted = false;
        }
        std::cout << "\n";

        // Drawing spacers
        if (h < height - 1)
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
    for (int w = 0; w < width - 1; w++)
    {
        std::cout << IPU << SLH;
    }
    std::cout << CBR << "\n";
}
