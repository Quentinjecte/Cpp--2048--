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

//// Draw the gameObj at a coordinate
//void GameObj::drawTile(SDL_Renderer* ARGrenderer, int ARGvalue, int ARGpos[2])
//{
//
//
//	// Sets the text for the tile (if any)
//	if (ARGvalue != 0)
//	{
//
//		// Get the dimensions of the text
//		int textWidth = textSurface->w;
//		int textHeight = textSurface->h;
//
//		// Set the position for the text within the tile
//		int textX = rowOffset + (background.w - textWidth) / 2;  // Centered horizontally
//		int textY = colOffset + (background.h - textHeight) / 2; // Centered vertically
//
//		// Create a destination rectangle for the text
//		SDL_Rect textDestRect = { textX, textY, textWidth, textHeight };
//
//		// Render the text to the renderer
//		SDL_RenderCopy(ARGrenderer, textTexture, nullptr, &textDestRect);
//
//		// Clean up the surface and texture
//		SDL_FreeSurface(textSurface);
//		SDL_DestroyTexture(textTexture);
//	}
//
//
//	SDL_RenderFillRect(ARGrenderer, &(this->background));
//}

// ChatGPT generated drawTile()
void GameObj::drawTile(SDL_Renderer* ARGrenderer, int ARGvalue, int ARGpos[2])
{
	if (TTFArial == nullptr) {
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
		return;
	}

	std::cout << "Start Error : " << SDL_GetError() << "\n";

	// Offset values to draw the rect at the right place
	int rowOffset = 0 + ARGpos[0] * 5;
	int colOffset = 0 + ARGpos[1] * 5;
	this->background.x = rowOffset;
	this->background.y = colOffset;

	// Sets the color of the background and renders it
	SDL_Color tileColor = this->colorMap.at(ARGvalue);
	SDL_SetRenderDrawColor(ARGrenderer, tileColor.r, tileColor.g, tileColor.b, 255);
	//SDL_RenderFillRect(ARGrenderer, &(this->background));

	// Sets the text for the tile (if any)
	if (ARGvalue != 0)
	{
		// Creates Surface and Texture to render the text
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(this->TTFArial, this->label, { 255, 255, 255 });
		std::cout << "Surf Error : " << SDL_GetError() << "\n";
		SDL_Texture* textureMessage = SDL_CreateTextureFromSurface(ARGrenderer, surfaceMessage);
		std::cout << "Texture Error : " << SDL_GetError() << "\n";

		SDL_Rect messageRect;
		messageRect.x = rowOffset;
		messageRect.y = colOffset;
		messageRect.w = this->background.w;
		messageRect.h = this->background.h;

		SDL_QueryTexture(textureMessage, NULL, NULL, &messageRect.w, &messageRect.h);
		std::cout << "Query Error : " << SDL_GetError() << "\n";
		SDL_RenderCopy(ARGrenderer, textureMessage, NULL, &messageRect);
		std::cout << "Render Error : " << SDL_GetError() << "\n";
		SDL_DestroyTexture(textureMessage);
		std::cout << "Destroy Error : " << SDL_GetError() << "\n";
		SDL_FreeSurface(surfaceMessage);
		std::cout << "Free Error : " << SDL_GetError() << "\n";

	}

}