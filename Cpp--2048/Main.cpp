// Cpp--Console--2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include "./board.hpp"
#include "./tile.hpp"
#include <conio.h>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <string>

// Value of input
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 1

int MaxN = 0;

int main()
{
    srand(time(NULL));

    int boardSize[] = { 4, 4 };

    Board board(boardSize);
    std::cout << "try 30 \n";

    while (true)
    {
        // Values and utilities

        board.spawnTiles();
        std::cout << "try 65\n";

        Tile::peek();
        std::cout << "try 68\n";

        board.drawBoard();
        std::cout << "Does a action \n";
        board.moveTiles();
        std::cout << "Try to get the coord\n";
        
        char key = _getch();
        int value = key;

        while (value != KEY_X)
        {
            switch (_getch())
            {
            case KEY_DOWN:
                std::cout << "KeyDown \n\n";
                break;
            case KEY_UP:
                std::cout << "KeyUp \n\n";
                break;
            case KEY_LEFT:
                std::cout << "KeyLeft \n\n";
                break;
            case KEY_RIGHT:
                std::cout << "KeyRight \n\n";
                break;
            }
            break;
        }
    }

    for (Tile* T : Tile::tileList) 
    {
        delete T;
    }
    return 0;
}