#ifndef BOARD_HPP
#define BOARD_HPP

#include "./tile.hpp"

class Board
{
private:
    int width;
    int height;
    int St = 2;

    TileSet* tileSet;

public:
    Board(int size[], TileSet* tileSetPtr);
    ~Board();

    void spawnTiles();
    void drawBoard();
    void moveTiles(char direction); // RUINED

    bool chkLoss();
    bool chkWin();
};

#endif
