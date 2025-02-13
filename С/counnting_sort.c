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

void FillArr(uint32_t* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 200000;
    }
}

int max(int32_t* arr, int n)
{
    int maxi = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxi)
            maxi = arr[i];
    }

    return maxi;
}

void counting_sort(uint32_t* arr, int n)
{
    int size = max(arr, n) + 1;

    uint32_t* new_arr = (uint32_t*)malloc(sizeof(uint32_t) * size);

    for(int i = 0; i < size; i++)
    {
        new_arr[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        new_arr[arr[i]]++;
    }

    for(int i = 0, j = 0; i < size; i++)
    {
        while(new_arr[i] != 0)
        {
            arr[j] = i;
            j++;
            new_arr[i]--;
        }
    }
}



int main()
{
    printf("Enter size of array: \n");

    uint32_t n;

    scanf("%d", &n);

    uint32_t* arr = (uint32_t*)malloc(sizeof(uint32_t) * n);

    FillArr(arr, n);

    double start = wtime();
    counting_sort(arr, n);
    double end = wtime();

    printf("Time: %lf\nRusult: \n", end - start);

    /*for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/






}