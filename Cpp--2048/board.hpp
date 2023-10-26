#ifndef BOARD_HPP
#define BOARD_HPP
#endif

class Board
{
private:
    int width;
    int height;
    int St = 2;

public:
    Board(int size[]);
    ~Board();

    void spawnTiles();
    void drawBoard();
    void moveTiles();
};

