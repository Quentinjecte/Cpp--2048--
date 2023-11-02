#include <iostream>
#include "./gameObj.hpp"

// Setting the static attirbutes
TTF_Font* GameObj::TTFArial = TTF_OpenFont("arial.ttf", 10);
std::map<int, SDL_Color> GameObj::colorMap = {
	{   0, {205, 193, 180}},
	{   2, { 238, 228, 218 }},
	{   4, { 237, 224, 200 }},
	{   8, { 242, 177, 121 }},
	{  16, { 245, 149,  99 }},
	{  32, { 246, 124,  95 }},
	{  64, { 246,  94,  59 }},
	{ 128, { 237, 207, 114 }},
	{ 256, { 237, 204,  97 }},
	{ 512, { 237, 200,  80 }},
	{1024, { 237, 197,  63 }},
	{2048, { 237, 194,  46 }}
};


// Constru & Destru
GameObj::GameObj(int ARGdim[2], char* ARGlabel)
{
	this->label = ARGlabel;
	this->background = { 0, 0, ARGdim[0], ARGdim[1] };
}
GameObj::~GameObj()
{
	std::cout << "GameObj was PURGED";
}

// Draw the gameObj at a coordinate
void GameObj::drawTile(SDL_Renderer* ARGrenderer, int ARGvalue, int ARGpos[2])
{
	// Offset values to draw the rect at the right place
	int rowOffset = 0 + ARGpos[0] * 5;
	int colOffset = 0 + ARGpos[1] * 5;
	this->background.x = rowOffset;
	this->background.y = colOffset;

	// Sets the color of the background
	SDL_Color tileColor = this->colorMap.at(ARGvalue);
	SDL_SetRenderDrawColor(ARGrenderer, tileColor.r, tileColor.g, tileColor.b, 255);

	// Sets the text for the tile (if any)


	SDL_RenderFillRect(ARGrenderer, &(this->background));
}