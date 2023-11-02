#ifndef GAME_OBJ
#define GAME_OBJ

#include <map>
#include "SDL.h"
#include "SDL_ttf.h"

class GameObj
{
private:
	// Font used for every Tiles of 2048
	static TTF_Font* TTFArial;

	// Colors used for the tiles background of 2048
	static std::map<int, SDL_Color> colorMap;

	// Attributes
	char* label;
	SDL_Rect background;

public:
	// Constru & Destru
	GameObj(int ARGdim[2], char* ARGlabel);
	~GameObj();

	// Methods to manipulate object
	void drawTile(SDL_Renderer* ARGrenderer, int ARGvalue, int ARGpos[2]);
};
#endif