#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_mixer.h"
#include <string>

class windows
{

private:
    std::string _title;
    int _x, _y;
    int _w = 1920;
    int _h = 1080;
    int Space = 5;

    bool init();
    bool _closed = false;

    SDL_Window* _windows;
    SDL_Renderer* _renderer;
    SDL_Surface* backgroundSurface;
    SDL_Texture* backgroundTexture;
    Mix_Music* music;
    SDL_Rect rect;

public:
    windows(const std::string& title, int w, int h);
    ~windows();

    void pollEvents();
    void DrawForm();

    inline bool isClosed() const { return _closed; }

    //Set the coor 
    windows() : _title("Default Title"), _x(), _y(), _w(), _h() { }
    int getWindowsX() const { return _x; }
    int getWindowsY() const { return _y; }
    int getWindowsW() const { return _w; }
    int getWindowsH() const { return _h; }
    SDL_Rect getRect() const { return rect; }

    // Getters
    SDL_Renderer* getRenderer();
};