class Tile
{
private:
    int value;
    int coord[2];

public:
    Tile(int value, int coord[]);
    ~Tile();

    void doubleValue();
};