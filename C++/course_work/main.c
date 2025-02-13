#include "header.h"

int main(int argc, char** argv)
{
    char str[15]; //временная строка, где будет храниться ввод
    int number[100]; //массив для введенной пользователем числовой последовательности
    int size_number = 0; //размер массива
    if(argc <= 2) //если аргументов из треминала недостаточно для работы
    {
        char end[] = "end\n"; //строка, прекращающая ввод
        printf("Arguments not founnd.Do you want to enter arguments from the keyboard?\nY/N\n"); // сообщение от ошибке и предложение ввести аргументы с клавиатуры
        fgets(str, 15, stdin); //ввод
        while(1)
        {
            if(strlen(str) != 2) //если ввели не символ
            {
                if(strcmp(str, end) == 0) //если ввели end
                    break; // выход из цикла
                    
                printf("Invalid argument.Try again:\n"); //сообщение об ошибке
                fgets(str, 15, stdin); //повтороный ввод
            }

            else
            {
                if(str[0] == 'Y' || str[0] == 'y') //если ввели Y
                {
                    printf("Enter arguments.'end' - end of input\n"); //начинается ввод последовательности
                    fgets(str, 15, stdin); //ввод

                    while(1)
                    {
                        if(strcmp(str, end) == 0) //если ввели end
                            break; //выход из цикла

                        if(Is_Number(str) && string_to_int(str) > 0) //если ввели число большее 0
                        {
                            number[size_number++] = string_to_int(str); //добавляем число в массив и увеличиваем размер массива
                            fgets(str, 15, stdin); //вводим следующее число
                        }

                        else //если ввели не число и не end
                        {
                            printf("Invalid argumnet.Try again:\n"); //сообщение об ошибке
                            fgets(str,15,stdin); //повторный ввод
                        }
                    }
                }

                else if(str[0] == 'N' || str[0] == 'n') //если ввели n
                {
                    return 0; //выход из программы 
                }

                else // если ни одно из условий не выполнилось
                {
                    printf("Invalid argument.Try again:\n"); //сообщение об ошибке
                    fgets(str, 15, stdin); //повторный ввод
                }
            }
        }
        
    }

    else //если аргументов из терминала хватило
    {
        for(int i = 1, j = 0; i < argc; i++)
        {
            if(!Is_Number(argv[i]) || string_to_int(argv[i]) < 0) //если аргумент - не число или число отрциательное
            {
                printf("invalid argument at %d position\nSelect action:\n1.Exit\n2.Continue\n", i); //сообщение от ошибке
                fgets(str, 15, stdin); //ввод действия

                while(1) //проверка ввода до тех пор, пока он не окажется верным 
                {
                    if(Is_Number(str)) //если введеная строка - число
                    {
                        if(string_to_int(str) == 1) //если это число 1, выходим из программы
                        {
                            return 0;
                        }

                        else if(string_to_int(str) > 2 || string_to_int(str) < 1) //если число не равно 1 или 2
                        {
                            printf("Invalid argument. Try again: \n"); //сообщение об ошибке
                            fgets(str, 15, stdin); //повтороный ввод
                        }

                        else if(string_to_int(str) == 2) //если пользователь решил продолжить работу без какого то элемента
                        {
                            break;//выход из цикла
                        }
                    }

                    else //если строка это не число
                    {
                        printf("Invalid argument. Try again:\n"); //сообщение об ошибке
                        fgets(str, 15, stdin); //повтороный ввод
                    }
                }
            }

            else //если аргумент подходит
            {
                number[j++] = string_to_int(argv[i]); //записываем в массив элемент
                size_number++; //увеличиваем размер массива
            }
        }

    }

    printf("Simple alghoritm: \n\n");
    
    int sum = number[size_number-1]; //искомая сумма - последний элемент массива

    size_number--; //уменьшаем размер массива, чтобы искомая сумма не участвоала в вычислениях
    
    double start = wtime();//время до начала алгоритма
    
    simple_bag_alghoritm(number, size_number, sum); //запуск простого алгоритма 

    double end = wtime();//после выполнения алгоритма
    
    printf("\nTime: %lf\n", end - start); //время работы алгоритма
    
    printf("\n\nHard alghoritm:");
    
    start = wtime();
    
    hard_bag_alghoritm(number, size_number, sum); //запуск сложного алгоритма
    
    end = wtime();
    
    printf("\nTime: %lf\n", end - start);
    
    return 0;
}