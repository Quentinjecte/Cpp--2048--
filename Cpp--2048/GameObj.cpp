#include <iostream>
#include <string>
#include "./gameObj.hpp"

// Setting the static attirbutes
TTF_Font* GameObj::TTFArial = TTF_OpenFont("C::Users:bboismenu/source/repos/Quentinjecte/Cpp--2048--/Cpp--2048/arial.ttf", 10);
std::map<int, SDL_Color> GameObj::colorMap = {
	{   0, { 205, 193, 180 }},
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
	SDL_Rect rect = _windows.getRect();
	int cellSize = 150;
	int cellSpacing = 5;
	int totalWidth = 4 * cellSize + 3 * cellSpacing;
	int totalHeight = 4 * cellSize + 3 * cellSpacing;

	int row = _windows.getWindowsR();
	int col = _windows.getWindowsC();

	std::cout << col << " GO \n";

	int startX = _windows.getWindowsX() + (_windows.getWindowsW() - totalWidth) / 2;
	int startY = _windows.getWindowsY() + (_windows.getWindowsH() - totalHeight) / 2;

	int centerX = startX + row * (cellSize + cellSpacing) + cellSize / 2;
	int centerY = startY + col * (cellSize + cellSpacing) + cellSize / 2;

	this->background.x = centerX;
	this->background.y = centerY;


    rect.w = 150;
    rect.h = 150;
    rect.x = centerX - rect.w / 2;
    rect.y = centerY - rect.h / 2;

	// Sets the color of the background
	SDL_Color tileColor = this->colorMap.at(ARGvalue);
	SDL_SetRenderDrawColor(ARGrenderer, tileColor.r, tileColor.g, tileColor.b, 255);

	// Sets the text for the tile (if any)

	SDL_RenderFillRect(ARGrenderer, &(this->background));
	SDL_RenderPresent(ARGrenderer); // Update the renderer
}
