#include "sort.h"

static int C = 0, M = 0;

void heap_max(int* arr, int size, int i)
{
    int temp;
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[large])
    {
        large = left;
        C++;
    }
    if(right < size && arr[right] > arr[large])
    {
        large = right;
        C++;
    }
    if(large != i)
    {
        C++;
        temp = arr[large];
        arr[large] = arr[i];
        arr[i] = temp;
        M+=3;
        heap_max(arr, size, large);
    }
}

void heap_sort_increase(int* arr, int size)
{
    int temp;
    for(int i = size / 2 - 1; i >= 0; i--)
        heap_max(arr, size, i);
    for(int i = size - 1; i >= 0; i--)
        {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            M+=3;
            heap_max(arr,i, 0);
        }

    printf("C = %d\nM = %d\n", C, M);

}

void heap_min(int* arr, int size, int i)
{
    int temp;
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] < arr[large])
    {
        large = left;
        C++;
    }
    if(right < size && arr[right] < arr[large])
    {
        large = right;
        C++;
    }
    if(large != i)
    {
        temp = arr[large];
        arr[large] = arr[i];
        arr[i] = temp;

        M+=3;
        heap_min(arr, size, large);
    }
}

void heap_sort_decrease(int* arr, int size)
{
    int temp;
    for(int i = size / 2 - 1; i >= 0; i--)
        heap_min(arr, size, i);
    for(int i = size - 1; i >= 0; i--)
        {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            M+=3;

            heap_min(arr,i, 0);
        }

    printf("C = %d\nM = %d\n", C, M);

}
