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
    IMG_Quit();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

/*
 * Setting the windows
 * Setting renderer
 */
bool windows::init()
{
    // Initiates SDL2, SDL2_TTF and SDL2_Image (in PNG mode)
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed init";
        return 0;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "IMG_Init() failed: " << IMG_GetError() << std::endl;
        return 0;
    }

    if (backgroundSurface == nullptr) {
        std::cerr << "Failed to load background image: " << IMG_GetError() << std::endl;
        // Error setting
    }

    //Music setting information
    if (Mix_Init(MIX_INIT_MP3) < 0) {
        std::cerr << "Failed to initialize SDL Mixer: " << Mix_GetError() << std::endl;
        return 0;
    }

    //Hz, type audio, size
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to open audio: " << Mix_GetError() << std::endl;
        return 0;
    }

    music = Mix_LoadMUS("Song.mp3");

    Mix_PlayMusic(music, -1); // Loop


    // Size windows setting information
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

    // Create a windows color
    _renderer = SDL_CreateRenderer(_windows, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr)
    {
        std::cerr << "Failed rendere";
        return 0;
    }
    return true;

}

// Window events handler
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
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // Set First background color
    SDL_RenderClear(_renderer);

    // Background img
    backgroundSurface = IMG_Load("Plage.jpg");

    backgroundTexture = SDL_CreateTextureFromSurface(_renderer, backgroundSurface);

    SDL_SetTextureColorMod(backgroundTexture, 128, 128, 128); // Low light
    // Dessinez la texture du fond sur toute la fenêtre
    SDL_RenderCopy(_renderer, backgroundTexture, nullptr, nullptr);
    SDL_DestroyTexture(backgroundTexture);
    SDL_FreeSurface(backgroundSurface);


    // Draw Table
    rect.w = 150;
    rect.h = 150;

    int startX = (_w - (4 * rect.w + 3 * Space)) / 2; // Space 
    int startY = (_h - (4 * rect.h + 3 * Space)) / 2;

    for (int i = 0; i < 4; i++)
    {
        SDL_SetRenderDrawColor(_renderer, 175, 175, 175, 255); // Set rectangle color
        for (int j = 0; j < 4; j++)
        {

            // Calculate the position of the current rectangle
            rect.x = startX + i * (rect.w + Space); // Position x 
            rect.y = startY + j * (rect.h + Space); // Position y 

            std::cout << rect.x << "\n";
            std::cout << rect.y << "\n";

            std::cout << rect.x << "\n";
            std::cout << rect.y << "\n";

            SDL_RenderFillRect(_renderer, &rect); // Draw the rectangle
        }
    }
    _x = rect.x;
    _y = rect.y;
    SDL_RenderPresent(_renderer); // Update the renderer
}

// Getters
SDL_Renderer* windows::getRenderer()
{
    return this->_renderer;
}
int windows::getWidth()
{
    return this->_w;
}
int windows::getHeight()
{
    return this->_h;
}