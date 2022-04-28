#pragma once

#if !defined(VARIABLE_INCLUDED)

#include "variables.hpp"

#endif

#if !defined(HEADER_INCLUDED)

#include "headers.hpp"

#endif

/*Initializa the SDL*/
bool initilaize();

/*Load the required media*/
bool loadMedia();

/*Display the array in the Window*/
void loadSelectionSortVisual(int *arr, int size);

/*Free up all the memory used by the SDL*/
void close();

/*The actual selection sort algorithm to sort the array*/
void selectionSort(int *arr, int size);
