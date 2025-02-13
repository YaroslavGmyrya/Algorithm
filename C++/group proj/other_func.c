#include "sort.h"

void FillArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000;
    }
}

void OutArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int Is_Number(char* num)
{
    int i = 0;
    if(num[0] == '-')
        i++;

    for(i; i < strlen(num) - 1; i++)
    {
        if(!((int)num[i] >= 48 && (int)num[i] <= 57))
            return 0;
    }

    return 1;
}

int string_to_int(char* num)
{
    int i = 0;
    int result = 0;
    if(num[0] == '-')
        i++;
    for(i; i < strlen(num) - 1; i++)
    {
        result += (int)num[i] - 48;
        result *= 10;
    }

    if(num[0] == '-')
        return -result / 10;
    else
        return result / 10;
}

void FillArray_Keyboard(int *arr, int size)
{
    char num[30];

    for(int i = 0; i < size; i++)
    {
        printf("Enter array element: ");
        fgets(num, 30, stdin);

        while(!Is_Number(num))
        {
            printf(RED"Dumb protection activated. Try again: "RESET);
            fgets(num, 30, stdin);
        }

        arr[i] = string_to_int(num);
    }
}