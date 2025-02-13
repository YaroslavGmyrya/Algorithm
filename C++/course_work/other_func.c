#include "header.h"

int binary_search(int* arr, int size, int key)
{
    int left = 0; 
    int right = size-1;
    int search = -1; 
    int step = 0;

    while (left <= right) 
    {
    step++;      
    int mid = (left + right) / 2; 

    if (key == arr[mid]) {  
        search = mid;     
        break;           
    }

    if (key < arr[mid])     
        right = mid - 1;  

    else                  
        left = mid + 1;   
    }

    if (search == -1)    
        return search;
    return search;
}

// получение текущего времени
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

// поиск максимального числа в массиве (для поразрядной сортировки)
int MaxLenNum(int *arr, int size)
{
    int max = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i]  > max)
            max = arr[i];
    }

    return max;
}

//сортировка подсчетом
int counter_sort(int* arr, int size, int div)
{
    int base = 10;

    int counter[base];
    int result[size];

    for(int i = 0; i < base; i++)
        counter[i] = 0;

    for(int i = 0; i < size; i++)
        counter[(arr[i]/div) % 10]++;

    for(int i = 1; i < base; i++)
        counter[i] += counter[i-1];

    for(int i = size-1; i >= 0; i--)
    {
        result[counter[(arr[i] / div)%10] - 1] = arr[i];
        counter[(arr[i] / div)%10]--;
    }

    for(int i = 0; i < size; i++)
        arr[i] = result[i];
}

//поразрядная сортировка
void radix_sort(int* arr, int size)
{
    int max = MaxLenNum(arr, size);
    for(int div = 1; div <= max; div*=10)
        counter_sort(arr, size, div);
}


//Код Грея (генерация всех возможных сумм чисел)
int** Gray_code(int k)
{
    int G_code[k+1];
    
    for(int i = 0; i < k+1; i++)
    {
        G_code[i] = 0;
    }

    int** result  = (int**)malloc(sizeof(int*)*pow(2,k));

    for(int i = 0; i < pow(2,k); i++)
    {
        result[i] = (int*)malloc(sizeof(int)*k);
    }

    int n = 0, m = 0, j = 0, counter = 0;
    while(counter != pow(2,k))
    {

        counter++;

        for(int i = k-1; i >= 0; i--)
        {
            result[n][m] = G_code[i];
            m++;
        }

        m = 0;
        n++;

        G_code[k] = 1 - G_code[k];

        if(G_code[k] == 1)
        {
            j = 0;
        }

        else
        {
            for(int c = 0; c < k + 1; c++)
            {
                if(G_code[c] == 1)
                {
                    j = c + 1;
                    break;
                }

            }
        }

        if (j >= k + 1)
            break;
        G_code[j] = 1 - G_code[j];
    }

    return result;
}

//Сумма бинарного кода по алфавиту key
int Gray_sum(int *G_code, int size, int* key)
{
    int tmp = 0;

    for(int i = 0; i < size; i++)
    {
        if(G_code[i] == 1)
            tmp += key[i];
    }

    return tmp;
}


//проверка строки на число
int Is_Number(char* num)
{
    int i = 0;

    if(num[0] == '-')
        i++;
        
    int k = strlen(num);

    do
    {
    if(!((int)num[i] >= 48 && (int)num[i] <= 57 && num[i]))
        return 0;
    i++;
    } while(i < strlen(num) - 1);

    return 1;
}

//перевод строки в число
int string_to_int(char* num)
{
    int i = 0;
    int result = 0;
    if(num[0] == '-')
        i++;
        
    do
    {
        result += (int)num[i] - 48;
        result *= 10;
        i++;
    } while(i < strlen(num) && num[i] != '\n');

    if(num[0] == '-')
        return -result / 10;
    else
        return result / 10;
}

//Перевод бинарной последовательности в конкретные числа из алфавита alphabet для простого алгоритма
void bin_code_to_number(int* code, int size, int* alphabet)
{
    for(int i = 0; i < size; i++)
    {
        if(code[i] == 1)
        {
            printf("%d ", alphabet[i]);
        }
    }
}
//Перевод бинарной последовательности в конкретные числа из алфавита alphabet для сложного алгоритма
void hard_bin_code_to_number(int* code, int first_size, int second_size, int* first_alphabet, int* second_alphabet)
{
    for(int i = 0; i < first_size; i++)
    {
        if(code[i] == 1)
        {
            printf("%d ", first_alphabet[i]);
        }
    }
    
    for(int i = 0; i < second_size; i++)
    {
       if(code[i+first_size] == 1)
        {
            printf("%d ", second_alphabet[i]);
        } 
    }
}