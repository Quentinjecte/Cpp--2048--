#include <iostream> // cout
#include <conio.h>  // _getch
#include <vector>
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

    // Pop-up windows already
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Salut", "Projet SDL", NULL);
    // Windows size
    windows window("2048", 1920, 1080);


    // Creates the GameObj instances
    std::vector<GameObj> listGameObj = {};
    int coord[2];
    for (int x = 0;  x < boardSize[0];  x++)
    {
        for (int y = 0;  y < boardSize[1];  y++)
        {
            coord[0] = x;
            coord[1] = y;
            GameObj* obj = new GameObj(tileSet.getTile(coord), coord);
            listGameObj.push_back(obj);
        }
    }

    // Main game loop
    board.spawnTiles();
    bool gameOver = false;
    while (!gameOver)
    {
        // Generating random tiles and drawing the board
        board.spawnTiles();
        // Updates every GameObj loaded in memory, and display them
        for (int x = 0; x < boardSize[0]; x++)
        {
            for (int y = 0; y < boardSize[1]; y++)
            {
                coord[0] = x;
                coord[0] = y;
                // Iterate through the objects using iterators and call the private dummy function
                for (std::vector<GameObj>::iterator it = listGameObj.begin(); it != listGameObj.end(); ++it)
                {
                    it->objUpdater(tileSet.getTile(coord));
                    it->drawTile(window.getRenderer(), window.getWidth(), window.getHeight());
                }
            }
        }
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