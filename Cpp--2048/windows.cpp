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
void windows::clear() const
{
    SDL_SetRenderDrawColor(_renderer, 135, 135, 135, 255); // Set background color
    SDL_RenderClear(_renderer);

    SDL_Rect rect;

    rect.w = 75;
    rect.h = 75;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            SDL_SetRenderDrawColor(_renderer, 255, 75, 0, 255); // Set rectangle color

            // Calculate the position of the current rectangle
            rect.x = i * rect.w;
            rect.y = j * rect.h;

            SDL_RenderFillRect(_renderer, &rect); // Draw the rectangle
        }
    }

    SDL_RenderPresent(_renderer); // Update the renderer
}

/*
 *
 */