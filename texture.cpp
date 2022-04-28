#include "texture.hpp"

/*
=============================================================
Starting of the body of the function defined in Class Texture
=============================================================
*/

Texture::Texture()
{
    mWidth = 0;
    mHeight = 0;
    mTexture = NULL;
}

Texture::~Texture()
{
    free();
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool Texture::loadFromRenderedText(std::string text, SDL_Color color)
{
    bool status = true;

    SDL_Surface *temporary_surface = TTF_RenderText_Solid(window_font, text.c_str(), color);

    if (temporary_surface == NULL)
    {
        std::cout << "SDL_Error :" << SDL_GetError() << std::endl;
        status = false;
    }
    else
    {
        mTexture = SDL_CreateTextureFromSurface(window_renderer, temporary_surface);
        if (mTexture == NULL)
        {
            std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
            status = false;
        }

        else
        {
            mWidth = temporary_surface->w;
            mHeight = temporary_surface->h;
        }

        SDL_FreeSurface(temporary_surface);
    }

    return status;
}
#endif

void Texture::free()
{
    if (mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect *renderRect, SDL_Rect *renderQuad, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    if (renderRect != NULL)
    {
        renderQuad->w = renderRect->w;
        renderQuad->h = renderRect->h;
    }

    // SDL_RenderCopy(game_renderer, mTexture, renderRect, NULL);

    SDL_RenderCopyEx(window_renderer, mTexture, renderRect, renderQuad, angle, center, flip);
}

int Texture::getWidth()
{
    return mWidth;
}

int Texture::getHeight()
{
    return mHeight;
}

void Texture::setValue(std::string value)
{
    this->value = value;
}