#include "sort.h"

void shakerSort_increase(int arr[], int size) {
    int C = 0;
    int M = 0;
    int left = 0;
    int right = size - 1;
    int swapped = 1;

    while (left < right && swapped) {
        swapped = 0;
        
        for (int i = left; i < right; i++) {
            C++;
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                M+=3;
            }
        }
        
        right--;

        for (int i = right; i > left; i--) {
            C++;
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
                M+=3;
            }
        }
        
        left++;
    }
    printf("C = %d\nM = %d\n", C, M);
}

void shakerSort_decrease(int arr[], int n) {
    int C = 0;
    int M = 0;
    int left = 0;
    int right = n - 1;
    int swapped = 1;

    while (left < right && swapped) {
        swapped = 0;

        for (int i = left; i < right; ++i) {
            C++;
            if (arr[i] < arr[i + 1]) { 
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                M+=3;
            }
        }

        right--;

        
        for (int i = right; i > left; --i) {
            C++;
            if (arr[i] > arr[i - 1]) { 
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
                M+=3;
            }
        }

        left++;
    }

    printf("C = %d\nM = %d\n", C, M);
}
