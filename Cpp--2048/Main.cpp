#include <iostream> // cout
#include <conio.h>  // _getch
#include "./board.hpp"
#include "./tile.hpp"

// Value of input
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 1

int main()
{
    srand(time(NULL));

    //Initializing default board
    int boardSize[] = { 4, 4 };
    TileSet tileSet(boardSize);
    Board board(boardSize, &tileSet);

    // Initializing debug previous Board
    Board prevBoard(boardSize, &tileSet);
    
    // Main game loop
    bool gameOver = false;
    while(!gameOver)
    {
        // $-DEBUG: Updating and drawing prevBoard for tile movement and fusion debuging
        std::cout << "Previous Board state : \n";
        prevBoard = board;
        board.drawBoard();

        // Generating random tiles and drawing the board
        board.spawnTiles();
        board.drawBoard();

        // Loss check (before player input since generation light have screwed them already)
        gameOver = board.chkLoss();

        // Wait for and treat the player's input
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

        // Win check (after the player input since they might have crated a 2048 tile :D
        //gameOver = board.chkWin();

        // TODO : Offer the opportunity to play again
    }
    

    return 0;
}