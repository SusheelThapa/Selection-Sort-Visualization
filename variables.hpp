#pragma once

#define VARIABLE_INCLUDED 1

#if !defined(HEADER_INCLUDED)

#include "headers.hpp"

#endif

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

SDL_Window *window;
SDL_Renderer *window_renderer;
SDL_Event e;
TTF_Font *window_font;
