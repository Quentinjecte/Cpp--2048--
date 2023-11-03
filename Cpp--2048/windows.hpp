#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_mixer.h"
#include <string>

struct Cells
{
    int x;
    int y;
};


class windows
{

private:
    std::string _title;
    int _x, _y;
    int _w = 1920;
    int _h = 1080;
    int Space = 5;
    int row;
    int col;

    bool init();
    bool _closed = false;

    SDL_Window* _windows;
    SDL_Renderer* _renderer;
    SDL_Surface* backgroundSurface;
    SDL_Texture* backgroundTexture;
    Mix_Music* music;
    SDL_Rect rect;
    SDL_Rect coord[4][4];


public:
    windows(const std::string& title, int w, int h);
    ~windows();

    void pollEvents();
    void DrawForm();

    inline bool isClosed() const { return _closed; }

    //Set the coor 
    windows() : _title("Default Title"), _x(-75), _y(-75), _w(1920), _h(1080) { }
    int getWindowsX() const { return _x; }
    int getWindowsY() const { return _y; }
    int getWindowsW() const { return _w; }
    int getWindowsH() const { return _h; }
    int getWindowsR() const { return row; }
    int getWindowsC() const { return col; }
    SDL_Rect getRect() const { return rect; }

    // Getters
    SDL_Renderer* getRenderer();
};