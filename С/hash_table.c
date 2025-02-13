#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define list struct ListNode



struct ListNode
{
    int value;

    struct ListNode* next;
};

static int col = 0;
double wtime()
{
 struct timeval t;
 gettimeofday(&t, NULL);
 return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
 return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

unsigned int AddHash(char *s, int size)
{


unsigned int h = 0;
 while (*s)
 h += (unsigned int)*s++;
 return h % size;
}

list* Create_Node(int value)
{
    list* node = (list*)malloc(sizeof(list));

    node->value = value;

    node->next = NULL;

    return node;
}


void init_hash_table(list** hash_table, int size)
{
    for(int i = 0; i < size; i++)
    {
        hash_table[i] = NULL;
    }
}



list* LookUp(list** hash_table, char* key, int size)
{
    uint hash = AddHash(key, size);
    if(hash_table[hash] == NULL)
        return NULL;

    return hash_table[hash];

}

void hash_table_delete(list** hash_table, int size)
{
    list* new_node = NULL;
    list* node = NULL;
    for(int i = 0; i < size; i++)
    {
        if(hash_table[i] != NULL)
        {
            node = hash_table[i];
            while(node != NULL)
            {
                new_node = node;
                node = node->next;
                free(new_node);
            }
        }
    }
    
    free(node);
    free(hash_table);
}

char* generate_word(int len)
{
    char* word = (char*)malloc(sizeof(char) * len + 1);
    word[len] = '\0';
    for(int i = 0; i < len; i++)
    {
        word[i] = (char)(getrand(33, 126));
    }

    return word;

}

void hash_table_add(list** hash_table, int value, char* key, int size)
{
    unsigned hash = AddHash(key, size);
    if(hash_table[hash] == NULL)
        hash_table[hash] = Create_Node(value);
    else
    {   
        col++;
        list* node = hash_table[hash];
        while(node->next != NULL)
        {
            node = node->next;
        }

        node->next = Create_Node(value);
    }
}

int main()
{
    srand(time(0));

    printf("Enter count of words: ");


    int count;

    scanf("%d", &count);

    FILE* file = fopen("sort_2.txt", "r");

    char** words = (char**)malloc(sizeof(char*) * count + 1);

    words[count] = '\0';

    for(int i = 0; i < count; i++)
    {
        words[i] = (char*)malloc(sizeof(char) * 30);
    }

    int k = 0;
    int m = 0;

   while ((words[k][m] = fgetc(file)) != EOF && k < count -1) {
        if (words[k][m] == '\n') {
            words[k][m] = '\0';
            k++;
            m = 0;
        }
        else m++;
    }

    fclose(file);

    list** hash_table = (list**)malloc(sizeof(list*) * count);

    init_hash_table(hash_table, count);

    char* tmp;
    list* l;
    double time;
    

   
    for(int i = 1; i < count; i++)
    {

    hash_table_add(hash_table,i, words[i], count);
        
    }


    double start = wtime();
    LookUp(hash_table, words[count-1], count);
    double end = wtime();

    printf("TIME: %lf", end - start);

    return 0;
}