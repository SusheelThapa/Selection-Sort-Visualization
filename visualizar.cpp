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

    /*Create window*/
    window = SDL_CreateWindow("Selection Sort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Unable to create window.\nSDL_Error:" << SDL_GetError() << std::endl;
        return false;
    }

    /*Create renderer from the window*/
    window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window_renderer == NULL)
    {
        std::cout << "Unable to create window renderer.\nSDL_Error:" << SDL_GetError() << std::endl;
        return false;
    }

    /*Loads font*/
    window_font = TTF_OpenFont("fonts/cascadia.ttf", 16);

    if (window_font == NULL)
    {
        std::cout << "Unable to load fonts.\nTTF_Error:" << TTF_GetError() << std::endl;
        return false;
    }

    /*Taking input from the user to sort*/
    for (int i = 0; i < TOTAL_BLOCK; i++)
    {
        blocks[i].loadFromRenderedText(std::to_string(blocks_value[i]), {0, 0, 139, 255});
    }

    visualizer_name.loadFromRenderedText("SELECTION SORT", {0, 0, 0, 255});

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

void selectionSort()
{
    int minimum, minimum_index, j;
    Texture minimum_value_block_texture;

    for (int i = 0; i < TOTAL_BLOCK; i++)
    {

        minimum_index = i;
        j = i + 1;

        while (j < TOTAL_BLOCK)
        {

            if (blocks_value[minimum_index] > blocks_value[j])
            {
                minimum_index = j;
            }
            j++;
        }
        loadSelectionSortVisual(i, minimum_index);

        minimum = blocks_value[minimum_index];
        blocks_value[minimum_index] = blocks_value[i];
        blocks_value[i] = minimum;

        minimum_value_block_texture = blocks[minimum_index];
        blocks[minimum_index] = blocks[i];
        blocks[i] = minimum_value_block_texture;
    }
    SDL_Delay(2000);
    exit(0);
}

void loadSelectionSortVisual(int highlight_one, int highlight_two)
{

    SDL_SetRenderDrawColor(window_renderer, 150, 43, 104, 255);
    SDL_RenderClear(window_renderer);

    SDL_Rect visualize_name_renderQuad = {(SCREEN_WIDTH - (BLOCK_WIDTH)*5) / 2,
                                          50,
                                          (BLOCK_WIDTH)*5,
                                          BLOCK_HEIGHT};
    visualizer_name.render(0, 0, nullptr, &visualize_name_renderQuad);

    SDL_SetRenderDrawColor(window_renderer, 150, 207, 104, 255);

    SDL_Rect block_rectange = {(SCREEN_WIDTH - (BLOCK_WIDTH + 60) * 5) / 2,
                               (SCREEN_HEIGHT - (40 + BLOCK_HEIGHT) * 3) / 2,
                               (60 + BLOCK_WIDTH) * 5,
                               (BLOCK_HEIGHT + 40) * 3};

    SDL_RenderFillRect(window_renderer, &block_rectange);
    SDL_Rect renderQuad;
    renderQuad = {(SCREEN_WIDTH - BLOCK_WIDTH * 5) / 2,
                  (SCREEN_HEIGHT - BLOCK_HEIGHT * 3) / 2,
                  BLOCK_WIDTH - 60,
                  BLOCK_HEIGHT};

    for (int i = 0; i < 5; i++)
    {
        if (i == highlight_one || i == highlight_two)
        {

            SDL_SetRenderDrawColor(window_renderer, 80, 200, 0, 255);
            SDL_RenderFillRect(window_renderer, &renderQuad);
        }
        blocks[i].render(0, 0, nullptr, &renderQuad);

        renderQuad.y += BLOCK_HEIGHT;
        if (i + 5 == highlight_two || i + 5 == highlight_one)
        {

            SDL_SetRenderDrawColor(window_renderer, 80, 200, 0, 255);
            SDL_RenderFillRect(window_renderer, &renderQuad);
        }
        blocks[i + 5].render(0, 0, nullptr, &renderQuad);

        renderQuad.y += BLOCK_HEIGHT;
        if (i + 10 == highlight_one || i + 10 == highlight_two)
        {

            SDL_SetRenderDrawColor(window_renderer, 80, 200, 0, 255);
            SDL_RenderFillRect(window_renderer, &renderQuad);
        }
        blocks[i + 10].render(0, 0, nullptr, &renderQuad);

        renderQuad.x += BLOCK_WIDTH + 30;
        renderQuad.y -= 2 * BLOCK_HEIGHT;
    }
    comparision_info.loadFromRenderedText("Comparision of " + std::to_string(blocks_value[highlight_one]) + " and " + std::to_string(blocks_value[highlight_two]), {0, 255, 0, 255});

    SDL_Rect comparision_info_rectangle = {
        (SCREEN_WIDTH - comparision_info.getWidth()-30) / 2,
        800,
        comparision_info.getWidth()+30, comparision_info.getHeight() +30};
    comparision_info.render(0, 0, nullptr, &comparision_info_rectangle);
    SDL_Delay(800);

    SDL_RenderPresent(window_renderer);
}