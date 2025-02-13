#include "sort.h"

int main()
{
    printf("Enter size of array: ");

    char str[30];

    fgets(str, 30, stdin);

    while(!(Is_Number(str) || string_to_int(str) <= 0))
    {
        printf(RED"Dumb protection activated. Try again: "RESET);
        fgets(str, 30, stdin);
    }   

    int size = string_to_int(str);

    int arr[size];

    printf("Select filling method:\n1.Random number\n2.From the keyboard\n");

    fgets(str, 30, stdin);

    while(!((string_to_int(str) == 1 || string_to_int(str) == 2) && Is_Number(str)))
    {
        printf(RED"Dumb protection activated. Try again: "RESET);
        fgets(str, 30, stdin);

    }

    int filling_method = string_to_int(str);

    if(filling_method == 1)
        FillArray(arr, size);
    else
        FillArray_Keyboard(arr, size);

     printf("Select array type:\n1.Increase\n2.Decrease\n3.Random\n");

    fgets(str, 30, stdin);

    while(!((string_to_int(str) > 0 && string_to_int(str) <= 3) && Is_Number(str)))
    {
        printf(RED"Dumb protection activated. Try again: "RESET);
        fgets(str, 30, stdin);
    }

    int array_type = string_to_int(str);

    switch(array_type)
    {
        case 1:
            heap_sort_increase(arr, size);
        break;

        case 2:
            heap_sort_decrease(arr, size);
        break;
    };

    printf("Select sort type:\n1.Heap sort\n2.Simple_include sort\n3.Shaker sort\n");

    fgets(str, 30, stdin);

    while(!((string_to_int(str) > 0 && string_to_int(str) <= 3) && Is_Number(str)))
    {
        printf(RED"Dumb protection activated. Try again: "RESET);
        fgets(str, 30, stdin);
    }

    int sort_type = string_to_int(str);

    printf("Select sort mod:\n1.Increase\n2.Decrease\n");

    fgets(str, 30, stdin);

    while(!((string_to_int(str) == 1 || string_to_int(str) == 2) && Is_Number(str)))
    {
        printf(RED"Dumb protection activated. Try again: "RESET);
        fgets(str, 30, stdin);
    }

    int sort_mod = string_to_int(str);

    switch(sort_type)
    {
        case 1:
            if(sort_mod == 1)
                heap_sort_increase(arr, size);
            else
                heap_sort_decrease(arr, size);
            break;
        case 2:
            if(sort_mod == 1)
                include_sort_increase(arr, size);
            else
                include_sort_decrease(arr, size);
            break;
        case 3:
            if(sort_mod == 1)
                shakerSort_increase(arr, size);
            else
                shakerSort_decrease(arr, size);
            break;
    };

    OutArray(arr, size);




}