#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED     "\033[1;31m"
#define RESET   "\033[0m" 
#define BLACK   "\e[0;30m"
#define WHITE   "\e[0;37m"

void FillArray(int* arr, int size);
void FillArray_Keyboard(int *arr, int size);
void OutArray(int* arr, int size);
int Is_Number(char* num);
int string_to_int(char* num);
void shakerSort_increase(int arr[], int size);
void shakerSort_decrease(int arr[], int size);
void include_sort_increase(int *arr, int size);
void include_sort_decrease(int *arr, int size);
void heap_max(int* arr, int size, int i);
void heap_sort_increase(int* arr, int size);
void heap_sort_decrease(int* arr, int size);
void heap_min(int* arr, int size, int i);
