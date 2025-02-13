#include "header.h"

list* list_init(int value)
{
    list* _list = (list*)malloc(sizeof(list));
    
    _list->value = value;
    
    return _list;
}



void list_add_end(list* _list, int value)
{
    list* tmp = _list;
    
    while(tmp->next)
    {
        tmp = tmp->next;
        
    }

    tmp->next = list_init(value);
}

void list_add_start(list** _list, int value)
{
    list* tmp = list_init(value);
    tmp->next = *_list;
    *_list = tmp;
}

void list_lookup(list* _list)
{
    list* tmp = _list;
    
    while(tmp)
    {
        printf("%d ", tmp->value);
        
        tmp = tmp->next;
    }

    printf("\n");
}

list* list_end(list* _list)
{
    list* tmp = _list;

    while(tmp->next)
    {
        tmp = tmp->next;
    }

    return tmp;
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

int Is_WSAD(char* str)
{
    if(!(strlen(str) == 1 || (str[0] == 'w' || str[0] == 's' || str[0] == 'a' || str[0] == 'd')))
        return 0;
    else
    {
        return 1;
    }
}

void help()
{
    printf("\n  rules:\n\n1.w - up\n2.s - down\n3.a - left\n4.d - right\n5.r - restart\n6.q - quit\n\n");
}