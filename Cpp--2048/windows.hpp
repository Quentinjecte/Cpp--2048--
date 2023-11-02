#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

struct Form
{
    SDL_Rect rect;
    Uint32 couleur;
};

class windows
{

private:
    std::string _title;
    int _x, _y;
    int _w = 1920;
    int _h = 1080;

    bool init();
    bool _closed = false;

    SDL_Window* _windows;
    SDL_Renderer* _renderer;
    SDL_Surface* _image;
    SDL_Surface* surface = NULL;
    SDL_Texture* texture, * tmp = NULL;


public:
    windows(const std::string& title, int w, int h);
    ~windows();

    void pollEvents();
    void DrawForm();

    inline bool isClosed() const { return _closed; }


    // Getters
    SDL_Renderer* getRenderer();
};
