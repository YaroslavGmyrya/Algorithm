#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED     "\033[1;31m"
#define RESET   "\033[0m" 

typedef struct list
{
    int value;
    struct list* next;
    struct list* next_2;
    
} list;

list* list_init(int value);
void list_add_end(list* _list, int value);
void list_add_start(list** _list, int value);
void list_lookup(list* _list);
list* list_end(list* _list);
int Is_Number(char* num);
int string_to_int(char* num);
int Is_WSAD(char* str);
void help();



