// Cpp--Console--2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "../Cpp--2048/board.hpp"
#include "../Cpp--2048/tile.hpp"
#include <conio.h>
#include <cstdlib>

// Value of input
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 1

//Function move tile with keyboard
int main()
{

    // Values and utilities
    int boardDim[2] = { 4, 4 };
    Tile* tileList[16];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << "/--/";
        }
        std::cout << "\n";
    }
    std::cout << "Ligne 31 \n\n";
    Board board(boardDim);


    std::cout << "Does a action \n\n";
 
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
    }
    return 0;
}
