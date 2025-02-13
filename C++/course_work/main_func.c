#include "header.h"

void simple_bag_alghoritm(int* number, int size_number, int sum)
{
    /*
    Обработанный массив введеной пользователем последовательности(number)
    Длина массива number(size_number)
    Сумма,которую необходима найти (sum)*/
    
    int** G_code = Gray_code(size_number); //матрциа всех возможных сумм
    int k = pow(2,size_number); //кол-во возможных сумм
    int answer[size_number]; //Массив для записи результата
    int tmp; //Времення переменная для хранения суммы кода Грэя
    int counter = 0; //Счетчик, сигнализирующий о том, что есть ответ
    for(int i = 0; i < k; i++) //Проход по строкам матрицы
    {
        tmp = Gray_sum(G_code[i], size_number, number);

        if(tmp == sum) //если нашли последовательность,сумма которой равна искомой
        {
            bin_code_to_number(G_code[i], size_number, number); //бинарную последовательность переводим в числа и выводим
            counter++;
            break;
        }
    }

        if(counter == 0) // если ответа нет
            printf("Answer not found");
}

void hard_bag_alghoritm(int* number, int size_number, int sum)
{
    /*На входе функция получает массив из чисел, введеных пользователем(number)
    Размер массива number(size_number)
    Искомую сумму(sum);
    */
    
    int answer[size_number]; // массив для записи ответа
    //делим массив пополам
    int first_part = size_number / 2; // размер первой части
    int second_part = size_number - first_part; // размер второй части

    int** first_part_Gray_Code = Gray_code(first_part); // матрица из всех сумм для первой части
    int** second_part_Gray_Code = Gray_code(second_part); //матрица из всех сумм для второй части

    int first_part_sum_size = pow(2,first_part); //количество сумм в первой части
    int second_part_sum_size = pow(2,second_part); // количество сумм во второй части

    int first_part_sum[first_part_sum_size]; //массив хранящий суммы(уже не в бинарном виде) для первой части
    int second_part_sum[second_part_sum_size]; //массив хранящий суммы(уже не в бинарном виде) для второй части
    
    int counter = 0; //счетчик, сигнализирующий о наличии ответа

    for(int i = 0; i < first_part_sum_size; i++) //цикл по массиву из сумм для первой части
        first_part_sum[i] = Gray_sum(first_part_Gray_Code[i], first_part, number); //заполняем его суммами

    for(int i = 0; i < second_part_sum_size; i++) //цикл по массиву из сумм для второй части
        second_part_sum[i] = Gray_sum(second_part_Gray_Code[i], second_part, number+first_part); //заполняем его суммами

    radix_sort(second_part_sum, second_part_sum_size); //поразрядная сортировка массива сумм для второй части(т.к в нем будет работать бинарный поиск)

    printf("\n\n");

    for(int i = 0; i < first_part_sum_size; i++) //цикл по первому массиву сумм
    {
        int result = binary_search(second_part_sum, second_part_sum_size, sum - first_part_sum[i]); //ищем во втором массиве такую сумму,равную разности искомой суммы и суммы из первой части
        if(result > -1) //если такое число есть
        {
            counter++; //увеличиваем счетчик
            
            for(int j = 0; j < first_part;j++)
            {
                answer[j] = first_part_Gray_Code[i][j]; //записываем в ответ бинарную последовательность,соотвествующую сумме из первой части
            }

            for(int m = 0; m < second_part_sum_size; m++)
            {
                if(second_part_sum[result] == Gray_sum(second_part_Gray_Code[m], second_part, number+first_part)) //ищем в матрице такую последователность,которая соответствует сумме из второй части
                {
                    for(int k = 0; k < second_part; k++) //запускаем цикл по такой последовательнотси
                    {
                        answer[k+first_part] = second_part_Gray_Code[m][k]; //дописываем вторую часть ответа
                    }

                    break;
                }
            }
            break;
        }
    }
    
    if(counter != 0) // если ответ есть
        hard_bin_code_to_number(answer, first_part, second_part, number, number + first_part);
    else //если ответа нет
        printf("Answer not found");
}