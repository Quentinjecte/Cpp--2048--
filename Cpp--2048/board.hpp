#ifndef BOARD_HPP
#define BOARD_HPP
#endif

class Board
{
private:
    int width;
    int height;

public:
    Board(int size[]);
    ~Board();

    void spawnTiles();
    void drawBoard();
};

