#ifndef TILE_HPP
#define TILE_HPP
#endif

#include <vector>

class Tile
{
private:
    int value;
    int coord[2];


public:
    // Constructors & Destructors
    Tile(int value, int coord[]);
    ~Tile();

    static std::vector<Tile*> tileList;
    void doubleValue();
    static void peek();

    friend class Board;
};

