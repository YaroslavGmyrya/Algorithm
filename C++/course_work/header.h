#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

int binary_search(int* arr, int size, int key);
double wtime();
int MaxLenNum(int *arr, int size);
int counter_sort(int* arr, int size, int div);
void radix_sort(int* arr, int size);
int** Gray_code(int k);
int Gray_sum(int *G_code, int size, int* key);
int Is_Number(char* num);
int string_to_int(char* num);
void bin_code_to_number(int* code, int size, int* alphabet);
void hard_bin_code_to_number(int* code, int first_size, int second_size, int* first_alphabet, int* second_alphabet);
void simple_bag_alghoritm(int* number, int size_number, int sum);
void hard_bag_alghoritm(int* number, int size_number, int sum);
