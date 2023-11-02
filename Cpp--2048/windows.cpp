#include "./windows.hpp"
#include <iostream>
#include "./tile.hpp"

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
    //----------------------------------------------------------------------------------------------

    //SDL_Surface* _windows:: _image = IMG_Load("Void.png");

    //SDL_BlitSurface(this->_image, NULL, _w,NULL);

    //----------------------------------------------------------------------------------------------
    // Create a windows color
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
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                while (_x >= -(_w / 2 - 400))
                {
                    _x -= 20;
                }
                std::cout << "tamer";
                break;
            case SDLK_RIGHT:
                while (_x <= _w / 2 - 400)
                {
                    _x += 20;
                }
                break;
            case SDLK_UP:
                while (_y >= -(_h / 2 - 400))
                {
                    _y -= 20;
                }

                break;
            case SDLK_DOWN:
                while (_y <= _h / 2 - 400)
                {
                    _y += 20;
                }
                break;
            case SDLK_SPACE:
                _closed = true;
                break;
            default:
                break;
            }
        default:
            break;
        }
    }

}


// Create a rederer color
void windows::DrawForm()
{
    //SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // Set First background color
    //SDL_RenderClear(_renderer);

    SDL_Rect rect;
    SDL_SetRenderDrawColor(_renderer, 110, 110, 100, 255); // Set Second rectangle color
    rect.w = 700;
    rect.h = 700;
    rect.x = (_w / 2) - (rect.w / 2) + _x;
    rect.y = (_h / 2) - (rect.h / 2) + _y;
    SDL_RenderFillRect(_renderer, &rect); // Draw the rectangle


    rect.w = 150;
    rect.h = 150;

    for (int i = 0; i < 4; i++)
    {
        SDL_SetRenderDrawColor(_renderer, 175, 175, 175, 255); // Set rectangle color
        for (int j = 0; j < 4; j++)
        {

            // Calculate the position of the current rectangle
            rect.x = (int)((i * 175) + ((_w / 2) - (rect.w * 2.25))) + _x;
            rect.y = (int)((j * 175) + ((_h / 2) - (rect.h * 2.25))) + _y;

            SDL_RenderFillRect(_renderer, &rect); // Draw the rectangle
        }
    }
    SDL_RenderPresent(_renderer); // Update the renderer
}

// Getters
SDL_Renderer* windows::getRenderer()
{
    return this->_renderer;
}
/*
 *
 */