#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double wtime()
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void merge_sort(uint32_t *array, int array_size)
{
    if (array_size <= 1) return;  // base case. Critical to implement it!!!
        
    int middle = array_size / 2;
    uint32_t *left = array;
    uint32_t *right = array + middle;
    // BEWARE! Using address arithmetics: pointer + number gives shifted array begin
    int left_size = middle;
    int right_size = array_size - left_size;

    // recursion goes here:
    merge_sort(left, left_size);
    merge_sort(right, right_size);
    
    // Merge these two already sorted parts of array:
    uint32_t *buffer = (uint32_t*)malloc(sizeof(uint32_t) * array_size);
    int left_i = 0;
    int right_i = 0;
    int buffer_i = 0;
    while (left_i < left_size && right_i < right_size) {
        if (left[left_i] <= right[right_i]) {
            // taking the lesser from the left part of array
            buffer[buffer_i] = left[left_i];
            left_i += 1;
            buffer_i += 1;
        } else {
            // taking the lesser from the right part of array
            buffer[buffer_i] = right[right_i];
            right_i += 1;
            buffer_i += 1;
        }
    }
    while (left_i < left_size) { // copying left elements from the left size (if there is left something)
        buffer[buffer_i] = left[left_i];
        left_i += 1;
        buffer_i += 1;
    }
    while (right_i < right_size) { // copying right elements from the right size (if there is right something)
        buffer[buffer_i] = right[right_i];
        right_i += 1;
        buffer_i += 1;
    }
    
    // copying from buffer to original array:
    for(int i = 0; i < array_size; i++) {
        array[i] = buffer[i];
    }
    free(buffer);
}

void FillArr(uint32_t* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 200000;
    }
}

void print_array(uint32_t *array, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array_size;
    printf("Enter size of array: \n");
    scanf("%d", &array_size);

    uint32_t *array = (uint32_t*)malloc(sizeof(uint32_t) * array_size);
    
    FillArr(array, array_size);
    double start = wtime();
    merge_sort(array, array_size);
    double end = wtime();
    //print_array(array, array_size);

    free(array);

    printf("Time: %lf", end - start);

    return 0;
}