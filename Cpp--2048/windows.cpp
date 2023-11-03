#include "./windows.hpp"
#include <iostream>
#include "./tile.hpp"

windows::windows(const std::string& title, int w, int h)
    : _title(title), _w(w), _h(h)
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

// For don't crash
void windows::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        int newRow = 0;
        int newCol = 0;

        switch (event.type)
        {
        case SDL_QUIT:
            _closed = true;
            break;
        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                newRow = -1;
                row += newRow;
                break;
            case SDLK_RIGHT:
                newRow = 1;
                row += newRow;
                break;
            case SDLK_UP:
                newCol = -1;
                col += newCol;
                std::cout << col;
                break;
            case SDLK_DOWN:
                newCol = 1;
                col += newCol;
                std::cout << col;
                break;
            case SDLK_SPACE:
                _closed = true;
                break;
            default:
                break;
            }
            break;
        default:
            break;

        }
        row += newRow;
        col += newCol;

    }

}


void windows::DrawForm()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // Couleur de fond
    SDL_RenderClear(_renderer);

    // Chargez l'image de fond depuis un fichier
    backgroundSurface = IMG_Load("Plage.jpg");
    backgroundTexture = SDL_CreateTextureFromSurface(_renderer, backgroundSurface);
    SDL_SetTextureColorMod(backgroundTexture, 128, 128, 128); // Luminosité réduite
    SDL_RenderCopy(_renderer, backgroundTexture, nullptr, nullptr);
    SDL_DestroyTexture(backgroundTexture);
    SDL_FreeSurface(backgroundSurface);


    // Taille d'une case et espacement
    Cells cells[4][4];
    int cellSize = 150;
    int cellSpacing = Space;
    int totalWidth = 4 * cellSize + 3 * cellSpacing;
    int totalHeight = 4 * cellSize + 3 * cellSpacing;

    int startX = (_w - totalWidth) / 2;
    int startY = (_h - totalHeight) / 2;

    // Calculez les coordonnées des cases et remplissez le tableau de coordonnées
    for (int i = 0; i < 4; i++) {
        SDL_SetRenderDrawColor(_renderer, 175, 175, 175, 150); // Couleur du rectangle
        for (int j = 0; j < 4; j++) {
            // Calculez la position de la case actuelle
            int cellX = startX + i * (cellSize + cellSpacing);
            int cellY = startY + j * (cellSize + cellSpacing);

            // Remplissez le tableau de coordonnées
            cells[i][j] = { cellX, cellY };

            // Dessinez le rectangle
            SDL_Rect rect = { cellX, cellY, cellSize, cellSize };
            SDL_RenderFillRect(_renderer, &rect);
        }
    }

    SDL_RenderPresent(_renderer); // Mettez à jour le rendu
}

// Getters
SDL_Renderer* windows::getRenderer()
{
    return this->_renderer;
}
/*
 *
 */