#ifndef TILE_HPP
#define TILE_HPP
#endif

#include <vector>

class Tile
{
private:
    int value;
    int coord[2];

    static std::vector<Tile*> tileList;

public:
    // Constructors & Destructors
    Tile(int value, int coord[]);
    ~Tile();

    void doubleValue();
    static void peek();

    friend class Board;
};

