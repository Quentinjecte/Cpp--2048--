#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

class TileSet
{
private:
    std::vector<std::vector<int>> tiles;

public:
    // Constructors & Destructors
    TileSet(int size[]);
    ~TileSet();

    // Getters
    int getTile(int coord[2]);

    // Setters
    void setTile(int value, int coord[2]);

    // "Journalists"
    bool valueScan(int value);
    bool isFull();

    // Complex data editors
    void mfUp();
    void mfDown();
    void mfLeft();
    void mfRight();
};

#endif
