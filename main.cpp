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
                
                SDL_SetRenderDrawColor(window_renderer, 150, 43, 104, 255);
                SDL_RenderClear(window_renderer);

                SDL_Rect renderQuad;
                renderQuad = {(SCREEN_WIDTH - BLOCK_WIDTH * TOTAL_BLOCK) / 2,
                              (SCREEN_HEIGHT - BLOCK_HEIGHT) / 2,
                              BLOCK_WIDTH,
                              BLOCK_HEIGHT};

                for (int i = 0; i < TOTAL_BLOCK; i++)
                {
                    blocks[i].render(0, 0, nullptr, &renderQuad);
                    renderQuad.x += BLOCK_WIDTH;
                }

                SDL_RenderPresent(window_renderer);
            }
        }
    }
    return 0;
}