#include "visualizar.hpp"

bool initialize()
{

    /*initialize function flag*/
    bool status = true;

    /*Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Unable to initialize SDL.\nSDL_GetError: " << SDL_GetError() << std::endl;
        status = false;
    }

#if defined(SDL_IMAGE_MAJOR_VERSION)

    /*Initialize SDL image()*/
    int image_flag = IMG_INIT_PNG;
    if (!(IMG_Init(image_flag) & image_flag))
    {
        std::cout << "Unable to initalize SDL Images.\nIMG_Error: " << IMG_GetError() << std::endl;
        status = false;
    }

#endif

#if defined(SDL_TTF_MAJOR_VERSION)

    /* Initialize SDL_ttf*/
    if (TTF_Init() == -1)
    {
        std::cout << "Unable to initalize SDL TTF.\nTTF_Error: " << TTF_GetError() << std::endl;
        status = false;
    }

#endif
    return status;
}

bool loadMedia()
{

    window = SDL_CreateWindow("Selection Sort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Unable to create window.\nSDL_Error:" << SDL_GetError() << std::endl;
        return false;
    }

    window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window_renderer == NULL)
    {
        std::cout << "Unable to create window renderer.\nSDL_Error:" << SDL_GetError() << std::endl;
        return false;
    }

    window_font = TTF_OpenFont("fonts/lazy.ttf", 28);

    if (window_font == NULL)
    {
        std::cout << "Unable to load fonts.\nTTF_Error:" << TTF_GetError() << std::endl;
        return false;
    }

    return true;
}

void close()
{

#if defined(SDL_TTF_MAJOR_VERSION)

    TTF_CloseFont(window_font);

#endif

    SDL_DestroyRenderer(window_renderer);
    SDL_DestroyWindow(window);

#if defined(SDL_TTF_MAJOR_VERSION)

    TTF_Quit();

#endif

#if defined(SDL_IMAGE_MAJOR_VERSION)

    IMG_Quit();

#endif

    SDL_Quit();
}
