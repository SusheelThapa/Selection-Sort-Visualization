#pragma once

#if !defined(HEADER_INCLUDED)

#include "headers.hpp"

#endif

#include "texture.cpp"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int BLOCK_WIDTH = 150;
const int BLOCK_HEIGHT = 150;
const int TOTAL_BLOCK = 6;

SDL_Window *window;
SDL_Event e;

#if !defined(RENDERER_EXIST)
#define GAME_RENDERER_EXIST 1
SDL_Renderer *game_renderer;
#endif

#if !defined(FONT_EXIST)
#define GAME_FONT_EXIST 1
TTF_Font *game_font;
#endif

Texture blocks[TOTAL_BLOCK];

/*Initialize the SDL*/
bool initilaize();

/*Load the required media*/
bool loadMedia();

/*Display the array in the Window*/
void loadSelectionSortVisual(int *arr, int size);

/*Free up all the memory used by the SDL*/
void close();

/*The actual selection sort algorithm to sort the array*/
void selectionSort(int *arr, int size);
