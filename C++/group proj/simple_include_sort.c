#include "sort.h"



void include_sort_increase(int *arr, int size)
{
    int C = 0;
    int M = 0;
    int tmp;
    for(int i = 1; i < size; i++)
    {
        int index = i;

        int value = arr[i];

        while((index > 0) && (arr[index - 1] > value))
        {
            arr[index] = arr[index - 1];
            index--;
            C++;
            M++;
        }

        arr[index] = value;
        M++;
        

    }

    printf("C = %d\nM = %d\n", C, M);

}


void include_sort_decrease(int *arr, int size)
{
    int C = 0;
    int M = 0;
    int tmp;
    for(int i = 1; i < size; i++)
    {
        int index = i;

        int value = arr[i];

        while((index > 0) && (arr[index - 1] < value))
        {
            arr[index] = arr[index - 1];
            index--;
            C++;
            M++;
        }

        arr[index] = value;
        M++;
        

    }

    printf("C = %d\nM = %d\n", C, M);

}
