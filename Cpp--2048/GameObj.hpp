#ifndef GAME_OBJ
#define GAME_OBJ

#include <map>
#include "SDL.h"
#include "./windows.hpp"

class GameObj
{
private:
	windows _windows; // Constructeur de windows

	// Sprites used for the tiles of 2048
	static std::map<int, SDL_Surface*> spriteMap;

	// Attributes
	int tileValue;
	int tilePos[2];

	// Surface loading stuff
	void loadSurfaces();
	void freeSurfaces();

public:
	// Constru & Destru
	GameObj(int ARGvalue, int ARGpos[2]);
	~GameObj();

	// Updater
	void objUpdater(int ARGvalue);

	// Methods to manipulate object
	void drawTile(SDL_Renderer* ARGrenderer, int windowWidth, int windowHeight);
};
#endif