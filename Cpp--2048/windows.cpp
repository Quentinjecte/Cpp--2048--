#include "./windows.hpp"
#include <iostream>

windows::windows(const std::string& title, int w, int h) : _title(title), _w(w), _h(h)
{
    if (!init())
    {
        _closed = true;
    }
    _closed = !init();
}

// Destroy everything
windows::~windows()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_windows);
    SDL_Quit();
}

/*
 * Setting the windows
 * Setting renderer
 */
bool windows::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed init";
        return 0;
    }

    // Size windows setting
    _windows = SDL_CreateWindow(_title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _w,
        _h,
        0);

    if (_windows == nullptr)
    {
        std::cerr << "failed windows";
        return 0;
    }

    // Now we can create a windows color
    _renderer = SDL_CreateRenderer(_windows, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr)
    {
        std::cerr << "Failed rendere";
        return 0;
    }
    return true;
}

// For don't crash
void windows::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _closed = true;
            break;
        default:
            break;
        }
    }
}


// Create a rederer color
void windows::DrawForm()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // Set First background color
    SDL_RenderClear(_renderer);

    SDL_Rect rect;
    SDL_SetRenderDrawColor(_renderer, 110, 110, 100, 255); // Set Second rectangle color
    rect.w = 580;
    rect.h = 580;
    rect.x = (_w / 2) - (rect.w / 2);
    rect.y = (_h / 2) - (rect.h / 2);
    SDL_RenderFillRect(_renderer, &rect); // Draw the rectangle



    rect.w = 125;
    rect.h = 125;

    for (int i = 0; i < 4; i++)
    {
        SDL_SetRenderDrawColor(_renderer, 175, 175, 175, 255); // Set rectangle color
        for (int j = 0; j < 4; j++)
        {

            // Calculate the position of the current rectangle
            rect.x = (int)((i*140) + ((_w / 2) - (rect.w * 2.175)));
            rect.y = (int)((j*140) + ((_h / 2) - (rect.h * 2.175)));

            SDL_RenderFillRect(_renderer, &rect); // Draw the rectangle
        }
    }
    SDL_RenderPresent(_renderer); // Update the renderer

}

/*
 *
 */