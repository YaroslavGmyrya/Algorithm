#include "header.h"

int main()
{
    printf("Enter number: ");

    char number[20];

    int counter = 1;

    int array[100];

    fgets(number, 20, stdin);

    while(string_to_int(number) != 0)
    {   
        if(!Is_Number(number))
        {
            printf(RED"Dumb protection activated. Try again: "RESET);
            fgets(number, 20, stdin);
        }

        else
        {
        array[counter++] = string_to_int(number);
        printf("Enter number: ");
        fgets(number, 20, stdin);
        }
    }


    list* odd = list_init(array[1]);

    list* even = list_init(array[2]);

    even->next_2 = odd;

    for(int i = 3; i < counter; i++)
    {
        if(i % 2 == 0)
        {
            list_add_start(&even, array[i]);
            list_end(odd)->next_2 = even;
        }

        else
        {
            list_add_end(odd, array[i]);
        }
    }

    if(counter % 2 == 0)
    {
        list_end(odd)->next_2 = even;
    }

    list_lookup(odd);
    list_lookup(even);

   
    help();

    printf("Enter command: ");

    char command[10];

    int identifier = 0;

    list* tmp = odd;

    fgets(command, 10, stdin);

    while(!(command[0] == 'q'))
    {
        if(!Is_WSAD(command))
        {
            printf(RED"Command undefined. Try again: "RESET);
            fgets(command, 10, stdin);
        }

        else
        {
            while(Is_WSAD(command))
            {

                if(command[0] == 'w' && identifier == 0)
                {
                    if(tmp == odd)
                    {
                        printf(RED"The command cannot be executed.You can use only 'd'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }
                        
                    else
                    {
                        printf(RED"The command cannot be executed.You can use 'd' or 's'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }

                }

                else if(command[0] == 'w' && identifier == 1)
                {
                    if(tmp->next == NULL)
                    {
                        tmp = list_end(even)->next_2;
                        identifier--;
                        printf("%d\n", tmp->value);
                        printf("Enter command:\n");
                        fgets(command, 10, stdin);
                    }
            
                    else
                    {
                        printf(RED"The command cannot be executed.You can use only 'a'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }
        
                }

                if(command[0] == 'd' && identifier == 0)
                {
                    if(tmp->next != NULL)
                    {
                        tmp = tmp->next;
                        printf("%d\n", tmp->value);
                        printf("Enter command:\n");
                        fgets(command, 10, stdin);
                    }

                    else
                    {
                        printf(RED"The command cannot be executed.You can use only 's'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }
                }

                else if(command[0] == 'd' && identifier == 1)
                {
                    if(tmp->next != NULL)
                    {
                        printf(RED"The command cannot be executed.You can use only 'a'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }

                    else
                    {
                        printf(RED"The command cannot be executed.You can use only 'w'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }
                    
                }

                if(command[0] == 's' && identifier == 0)
                {
                    if(tmp == odd)
                    {
                        printf(RED"The command cannot be executed.You can use only 'd'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }

                    else
                    {
                        tmp= tmp->next_2;
                        identifier++;
                        printf("%d\n", tmp->value);
                        printf("Enter command:\n");
                        fgets(command, 10, stdin);
                    }
                }

                else if(command[0] == 's' && identifier == 1)
                {
                    if(tmp->next != NULL)
                    {
                        printf(RED"The command cannot be executed.You can use only 'a'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }

                    else
                    {
                        printf(RED"The command cannot be executed.You can use only 'w'.Try again: "RESET);
                        fgets(command, 10, stdin);
                    }
                }
            

            if(command[0] == 'a' && identifier == 0)
            {
                if(tmp == odd)
                {
                    printf(RED"The command cannot be executed.You can use only 'd'.Try again: "RESET);
                    fgets(command, 10, stdin);
                }

                else
                {
                    printf(RED"The command cannot be executed.You can use 'd' or 's'.Try again: "RESET);
                    fgets(command, 10, stdin);
                }
            }

            else if(command[0] == 'a' && identifier == 1)
            {
                if(tmp->next != NULL)
                {
                    tmp = tmp->next;
                    printf("%d\n", tmp->value);
                    printf("Enter command:\n");
                    fgets(command, 10, stdin);
                }

                else
                {
                    printf(RED"The command cannot be executed.You can use only 'w'.Try again: "RESET);
                    fgets(command, 10, stdin);
                }
            }

            if(command[0] == 'r')
            {
                tmp = odd;
                printf("%d\n", tmp->value);
                printf("Enter command:\n");
                fgets(command, 10, stdin);
            }

        } 
        }
    }



    return 0;
}