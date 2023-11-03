#include <iostream> // cout
#include <conio.h>  // _getch
#include "./board.hpp"
#include "./windows.hpp"
#include "./tile.hpp"
#include "./gameObj.hpp"

#include "SDL.h"
#include "SDL_ttf.h"

// Value of input
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 1

int main(int argc, char* argv[])
{
    //Initializing default board
    int boardSize[] = { 4, 4 };
    TileSet tileSet(boardSize);
    Board board(boardSize, &tileSet);

    // Setting up the board
    board.spawnTiles();
    board.spawnTiles();
    board.spawnTiles();
    board.spawnTiles();

    // Pop-up windows already
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Salur", "Projet SDL", NULL);
    // Windows size
    windows window("SDL K", 1920, 1080);


    // $# DEBUG
    // Creating dummy gameObj and trying to show it on screen
    int dim[] = { 150, 150 };
    char label[] = "amogus";
    GameObj testTile(dim, label);
    int tilePos[] = { 0, 3 };

    window.DrawForm();

    bool gameOver = false;

    while (!gameOver) {
        window.pollEvents();
        testTile.drawTile(window.getRenderer(), 32, tilePos);
    }

    /*
    // Main game loop
    bool gameOver = false;
    while (!gameOver)
    {
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
                tileSet.mfDown();
                break;
            case KEY_UP:
                std::cout << "KeyUp \n\n";
                tileSet.mfUp();
                break;
            case KEY_LEFT:
                std::cout << "KeyLeft \n\n";
                tileSet.mfLeft();
                break;
            case KEY_RIGHT:
                std::cout << "KeyRight \n\n";
                tileSet.mfRight();
                break;
            }
            break;
        }
        //Win check
        board.chkWin();

        /*
        * Win check and lose check
        * Can choise play again or leave

        if (board.chkWin() == true || board.chkLoss() == true)
        {
            gameOver = board.Replay();
        }
    }
    */

    return 0;
}