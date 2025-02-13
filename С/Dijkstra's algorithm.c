#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
typedef struct node 
{
    int key; 
    int v_count; 
}node;

typedef struct heap 
{
    int maxsize; 
    int nnodes; 
    struct node *nodes; 
}heap;

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

struct heap *heap_create(int maxsize)
{
    heap *h = malloc(sizeof(*h));
    if (h != NULL) {
        h->maxsize = maxsize;
        h->nnodes = 0;
        h->nodes = malloc(sizeof(*h->nodes) * (maxsize + 1));
        
        if (h->nodes == NULL) 
        {
            return NULL;
        }
    }
    return h;
}

void heap_swap(node *a, node *b)
{
    node temp = *a;
    *a = *b;
    *b = temp;
}

void heap_min(heap *h, int i)
{
    while(1)
    {
        int temp;
        int large = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= h->nnodes && h->nodes[left].key < h->nodes[large].key)
        {
            large = left;
        }
        
        if(right <= h->nnodes && h->nodes[right].key < h->nodes[large].key)
        {
            large = right;
        }

        if(large == i)
            break;

        heap_swap(&h->nodes[i], &h->nodes[large]);
        i = large;
    }
}

node heap_extract_min(heap *h)
{
    node minnode = h->nodes[1];
    h->nodes[1] = h->nodes[h->nnodes--];
    heap_min(h, 1);

    return minnode;
}

int heap_decrease_key(heap *h, int index, int newkey)
{
    h->nodes[index].key = newkey;
    while (index > 1 && h->nodes[index].key < h->nodes[index / 2].key) 
    {
        heap_swap(&h->nodes[index], &h->nodes[index / 2]);
        index /= 2;
    }
    return index;
}

int heap_insert(heap *h, int key, int value)
{

    h->nnodes++;
    h->nodes[h->nnodes].key = key;
    h->nodes[h->nnodes].v_count = value;

    
    for (int i = h->nnodes; i > 1 && h->nodes[i].key < h->nodes[i / 2].key; i = i / 2)
        heap_swap(&h->nodes[i], &h->nodes[i / 2]);

    return 0;
}
int** create_G(int v)
{
    int** G = (int**)malloc(sizeof(int*)*v);

    for(int i = 0; i < v; i++)
    {
        G[i] = (int*)malloc(sizeof(int) * v);
    }

    return G;
}

int** fill_G(int** G, int v)
{
    for(int i = 0; i < v; i++)
    {
        G[i][i] = 0;
        for(int j = i+1; j < v; j++)
        {
            int tmp = rand() % 80 + 5;
            G[i][j] = tmp;
            G[j][i] = tmp;

        }
    }
}

void out_G(int** G, int v)
{
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            printf("%d ", G[i][j]);
        }

        printf("\n");
    }
}


void path(int v_count, int** G, int* d)
{
    int top[v_count];

    int end = v_count - 1;

    top[0] = end + 1;

    int k = 1;

    int weight = d[end];

    while(end != 0)
    {
        for(int i = 0; i < v_count; i++)
        {
            if(G[end][i] != 0)
            {
                int t_weight = weight - G[end][i];

                if(t_weight == d[i])
                {
                    weight = t_weight;
                    end = i;
                    top[k] = i + 1;
                    k++;
                }
            }
        }
    }

    printf("\n\n");

    for(int i = 0; i < k; i++)
    {
        printf("%d <- ", top[i]);
    }

}
void d(int v_count, heap* h, int* d, int** G, int* v)
{

int min, min_index;

node tmp;

for(int j = 0; j < v_count; j++)
{
    tmp = heap_extract_min(h);

    min = tmp.key;

    for(int i = 0; i < v_count; i++)
    {
    if(d[i] == min)
        min_index = i;
    }

        if(min != 1000)
        {
            
            for(int i = 0; i < v_count; i++)
            {
                if(G[min_index][i] != 0)
                {

                    int t = G[min_index][i] + min;

                    if(t < d[i])
                    {

                        d[i] = t;
                        heap_decrease_key(h, i, d[i]);
                        
                    }
                }
            }

            v[min_index] = 0;
    } 
        }

printf("\n\n");

for(int i = 0; i < v_count; i++)
{
    printf("%d ", d[i]);
}

}
int main()
{
    int v_count_1 = 20;

    int v_count_2 = 100;

    int** G = create_G(v_count_1);

    int** G2 = create_G(v_count_2);

    fill_G(G, v_count_1);

    fill_G(G2, v_count_2);

    out_G(G,v_count_1);

    printf("\n\n");

    out_G(G2,v_count_2);

    int d1[v_count_1];

    int d2[v_count_2];

    int v1[v_count_1];
    int v2[v_count_2];

    heap* h1 = heap_create(v_count_1);

    heap* h2 = heap_create(v_count_2);

    for(int i = 0; i < v_count_1; i++)
    {
        d1[i] = 1000;
        v1[i] = 1;
        heap_insert(h1,d1[i],i);
    }

    for(int i = 0; i < v_count_2; i++)
    {
        d2[i] = 1000;
        v2[i] = 1;
        heap_insert(h2,d2[i],i);
    }


    d1[0] = 0;
    d2[0] = 0;

    heap_decrease_key(h1, 1, 0);
    heap_decrease_key(h2, 1, 0);

    double start = wtime();
    d(v_count_1,h1,d1,G,v1);
    path(v_count_1, G ,d1);
    double end = wtime();

    printf("\n20*20: %lf", end - start);

    start = wtime();

    d(v_count_2,h2,d2,G2,v2);
    path(v_count_2, G2 ,d2);
    
    end = wtime();

    printf("\n100*100 grid: %lf", end - start);

    return 0;
}