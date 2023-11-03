#include <iostream>
#include <string>
#include "./GameObj.hpp"
#include "SDL_image.h"

std::map<int, SDL_Surface*> GameObj::spriteMap;

// Surface loading stuff
void GameObj::loadSurfaces()
{
	// Load surfaces and store them in the map
	spriteMap[2] = IMG_Load("Tiles/2.png");
	spriteMap[4] = IMG_Load("Tiles/4.png");
	spriteMap[8] = IMG_Load("Tiles/8.png");
	spriteMap[16] = IMG_Load("Tiles/16.png");
	spriteMap[32] = IMG_Load("Tiles/32.png");
	spriteMap[64] = IMG_Load("Tiles/64.png");
	spriteMap[128] = IMG_Load("Tiles/128.png");
	spriteMap[256] = IMG_Load("Tiles/256.png");
	spriteMap[512] = IMG_Load("Tiles/512.png");
	spriteMap[1024] = IMG_Load("Tiles/1024.png");
	spriteMap[2048] = IMG_Load("Tiles/2048.png");

	// Check if surfaces were loaded successfully
	for (const auto& pair : this->spriteMap) {
		if (pair.second == nullptr) {
			std::cout << "A loading of .png failed ! " << pair.first << " OOPS\n";
		}
	}
}
void GameObj::freeSurfaces()
{
	for (const auto& pair : this->spriteMap) {
		SDL_FreeSurface(pair.second);
	}
}

// Constru & Destru
GameObj::GameObj(int ARGvalue, int ARGpos[2])
{
	this->tileValue = ARGvalue;
	this->tilePos[0] = ARGpos[0];
	this->tilePos[1] = ARGpos[1];
}
GameObj::~GameObj()
{
	freeSurfaces();
	std::cout << "GameObj was PURGED\n";
}

// Updater
void GameObj::objUpdater(int ARGvalue)
{
	this->tileValue = ARGvalue;
}

// Methods to manipulate object
void GameObj::drawTile(SDL_Renderer* ARGrenderer, int windowWidth, int windowHeight)
{
	if (this->spriteMap.find(this->tileValue) != this->spriteMap.end())
	{
		// Creates the Texture of the tile
		SDL_Texture* tileTexture = SDL_CreateTextureFromSurface(ARGrenderer, this->spriteMap[this->tileValue]);

		// Determine the position and size for rendering
		int rectSize = 150; // Adjust this to match the size of your grid cells
		int space = 3; // Adjust this to match the space between cells
		int startX = (windowWidth - (4 * rectSize + 3 * space)) / 2;
		int startY = (windowHeight - (4 * rectSize + 3 * space)) / 2;

		// Creates and positions the Rect where the tile will be
		SDL_Rect tileRect;
		tileRect.x = startX + tilePos[0] * (rectSize + space);
		tileRect.y = startY + tilePos[1] * (rectSize + space);
		tileRect.w = rectSize;
		tileRect.h = rectSize;

		// Renders and cleans up
		SDL_RenderCopy(ARGrenderer, tileTexture, NULL, &tileRect);
		SDL_DestroyTexture(tileTexture);
	}

}