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

            SDL_SetRenderDrawColor(window_renderer, 150, 43, 104, 255);
            SDL_RenderClear(window_renderer);

            selectionSort();

            SDL_RenderPresent(window_renderer);
        }
    }
    return 0;
}