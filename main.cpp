

#if !defined(HEADER_INCLUDED)
#include "headers.hpp"
#endif

#include "visualizar.cpp"

int main()
{
    bool quit = false;

    if (initialize())
    {
        if (loadMedia())
        {
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        quit = true;
                    }
                }
                SDL_SetRenderDrawColor(window_renderer, 255, 255, 255, 255);
                SDL_RenderClear(window_renderer);

                SDL_RenderPresent(window_renderer);
            }
        }
    }
    return 0;
}