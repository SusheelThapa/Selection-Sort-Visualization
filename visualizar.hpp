#pragma once

#if !defined(HEADER_INCLUDED)

#include "headers.hpp"

#endif

#include "texture.cpp"

const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1000;
const int BLOCK_WIDTH = 140;
const int BLOCK_HEIGHT = 160;
const int TOTAL_BLOCK = 15;

SDL_Window *window;
SDL_Event e;
Texture visualizer_name;
Texture comparision_info;

#if !defined(RENDERER_EXIST)
#define GAME_RENDERER_EXIST 1
SDL_Renderer *game_renderer;
#endif

#if !defined(FONT_EXIST)
#define GAME_FONT_EXIST 1
TTF_Font *game_font;
#endif

int blocks_value[TOTAL_BLOCK] = {90, 37, 29, 30, 29, 50, 69, 29, 10, 40, 50, 30, 2, 58, 30};
Texture blocks[TOTAL_BLOCK];

/*Initialize the SDL*/
bool initilaize();

/*Load the required media*/
bool loadMedia();

/*Display the array in the Window*/
void loadSelectionSortVisual(int, int);

/*Free up all the memory used by the SDL*/
void close();

/*The actual selection sort algorithm to sort the array*/
void selectionSort(int *arr, int size);

void printArray();
