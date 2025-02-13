#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Vector {
private:
    T* data;         
    int capacity;  
    int length;    

    void reallocate(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < length; ++i) {
            new_data[i] = data[i]; 
        }
        delete[] data;  
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vector(){
        data = nullptr;
        capacity = 0;
        length = 0;
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (length == capacity) {
            int new_capacity = capacity == 0 ? 1 : capacity * 2;
            reallocate(new_capacity);
        }
        data[length++] = value;
    }

    int size() const {
        return length;
    }

    void clear() {
        length = 0;
    }

    T& operator[](int index) {
        return data[index];
    }

    bool empty() const {
        return length == 0;
    }


     T* begin() {
        return data;
    }

    T* end() {
        return data + length;
    }

     void erase(const T& value) {
        int index_to_erase = -1;
        for (int i = 0; i < length; ++i) {
            if (data[i] == value) {
                index_to_erase = i;
                break;
            }
        }

        if (index_to_erase == -1) {
            std::cout << "Element not found" << std::endl;
            return; 
        }

       
        for (size_t i = index_to_erase; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }

        --length; 
    }
};

template <class T>
class fibHeapNode
{
    public:
    int key;
    T value;
    fibHeapNode* parent;
    fibHeapNode* left;
    fibHeapNode* right;
    Vector<fibHeapNode*> child;
    int degree;
    bool mark;

    fibHeapNode<T>* pparent(fibHeapNode<T>* node);

    fibHeapNode<T>(int key, T value)
    {
        this->key = key;
        this->value = value;
        parent = this;
        left = this;
        right = this;
        degree = 0;
        mark = false;
    }
};

template <class T>
class FibHeap
{
    public:
    void insert(int key, T value);
    void LinkLists(FibHeap<T>* heap1, FibHeap<T>* heap2);
    FibHeap<T> Union(FibHeap<T>* heap1, FibHeap<T>* heap2);
    fibHeapNode<T>* mini;
    void insert(fibHeapNode<T>* node, FibHeap<T>* heap);
    void AddToRoot(fibHeapNode<T>* node, FibHeap<T>* mini);
    fibHeapNode<T>* DeleteMin(FibHeap<T>* heap);
    void RemoveRoot(fibHeapNode<T>* y, FibHeap<T>* heap);
    void Link(FibHeap<T>* heap, fibHeapNode<T>* y, fibHeapNode<T>* x);
    void Consolidate(FibHeap<T>* heap);
    void Swap(fibHeapNode<T>*& x, fibHeapNode<T>*& y);
    void CascadingCut(FibHeap<T>* heap, fibHeapNode<T>* y);
    void Cut(FibHeap<T>* heap, fibHeapNode<T>* x, fibHeapNode<T>* y);
    void DecreasKey(FibHeap<T>* heap, fibHeapNode<T>* x, int new_key);
    void RemoveChild(fibHeapNode<T>* y, fibHeapNode<T>* parent);
    void Delete(FibHeap<T>* heap, fibHeapNode<T>* x);


    int D(int a);
    int nnodes;
    private:
   

    

};

template <class T>
fibHeapNode<T>* fibHeapNode<T>::pparent(fibHeapNode<T>* node)
{
    if(node->parent == node)
        return node;
    return pparent(node->parent);
}
template <class T>
void FibHeap<T>::AddToRoot(fibHeapNode<T>* node, FibHeap<T>* heap)
    {
        fibHeapNode<T>* mini = heap->mini; 
        if(mini == nullptr)
        {
            heap->nnodes += 1;
            return;
        }
           
        
        if(mini->left == mini)
        {
            mini->left = node;
            mini->right = node;
            node->right = mini;
            node->left = mini;
        }

        else
        {
            fibHeapNode<T>* lnode = mini->left;
            mini->left = node;
            node->right = mini;
            node->left = lnode;
            lnode->right = node;
        }
        heap->nnodes += 1;
    }

template <class T>
void FibHeap<T>::insert(fibHeapNode<T>* node, FibHeap<T>* heap)
{
    AddToRoot(node, heap);
    if(mini== nullptr || node->key < mini->key)
    {
        mini = node;
    }
}

template <class T>
void FibHeap<T>::insert(int key, T value)
{
    fibHeapNode<T>* tmp = new fibHeapNode(key, value);
    insert(tmp,this);
    tmp = nullptr;
    delete tmp;
}

template <class T>
void FibHeap<T>::LinkLists(FibHeap<T>* heap1, FibHeap<T>* heap2)
{
    if(heap1 == nullptr || heap2 == nullptr)
        return;

    fibHeapNode<T>* left1 = heap1->mini->left;
    fibHeapNode<T>* left2 = heap2->mini->left;
    left1->right = heap2->mini;
    heap2->mini->left = left1;
    heap1->mini->left = left2;
    left2->right = heap1->mini;
}

template<class T>
FibHeap<T> FibHeap<T>::Union(FibHeap<T>* heap1, FibHeap<T>* heap2)
{
    FibHeap<T> new_heap;
    new_heap.mini = heap1->mini;
    new_heap.LinkLists(heap1, heap2);
    if((heap1->mini == nullptr) || (heap2->mini != nullptr && heap2->mini->key < new_heap.mini->key))
    {
        new_heap.mini = heap2->mini;
    }

    new_heap.nnodes = heap1->nnodes + heap2->nnodes;

    heap1 = nullptr;
    heap2 = nullptr;
    delete heap1;
    delete heap2;
    return new_heap;
    
}
template<class T>
int FibHeap<T>::D(int a)
{
    return floor(log2(a)) + 1;
}

template <class T>
void FibHeap<T>::Swap(fibHeapNode<T>*& x, fibHeapNode<T>*& y)
{
    if(this->nnodes == 2)
    {
        fibHeapNode<T>* tmp = y;
        y = x;
        x = tmp;
        return;
    }
    fibHeapNode<T>* left_x = x->left;
    fibHeapNode<T>* right_x = x->right;
    fibHeapNode<T>* left_y = y->left;
    fibHeapNode<T>* right_y = y->right;
    fibHeapNode<T>* tmp = y;

    left_x->right = right_x;
    right_x->left = left_x;
    left_x->left = x;
    left_y->right = x;
    x->left = left_y;
    x->right = y;

    y = x;
    x = tmp;
}

template <class T>
void FibHeap<T>::Consolidate(FibHeap<T>* heap)
{
    if(heap->nnodes == 1)
        return;
    int size = D(heap->nnodes);
    fibHeapNode<T>* A[size];

    for(int i = 0; i < size; ++i)
        A[i] = nullptr;
    
    fibHeapNode<T>* w = heap->mini;
    int node = heap->nnodes;
    int i = 0;
    while(i<node)
    {   
        fibHeapNode<T>* x = w;
        int d = x->degree;
        while(A[d] != nullptr)
        {
            fibHeapNode<T>* y = A[d];
            if(x->key > y->key)
            {
                Swap(x,y);
            }
            Link(heap,y,x);
            A[d++] = nullptr;
        }

        A[d] = x;
        w = w->right;
        ++i;
    
    }
    //heap->mini = nullptr;

    for(int i = 0; i < size; ++i)
    {
        if(A[i] != nullptr)
        {
            //heap->AddToRoot(A[i], heap);
            //heap->nnodes-=1;
            if(heap->mini == nullptr || A[i]->key < heap->mini->key)
                heap->mini = A[i];
        }
    }
}

template <class T>
void FibHeap<T>::Link(FibHeap<T>* heap, fibHeapNode<T>* y, fibHeapNode<T>* x)
{
    x->degree+=1;
    RemoveRoot(y, heap);
    y->parent = x;
    x->child.push_back(y);
    y->right = y;
    y->left = y;
    y->mark = false;

}

template <class T>
void FibHeap<T>::RemoveChild(fibHeapNode<T>* child, fibHeapNode<T>* parent)
{
    for(auto i = parent->child.begin(); i < parent->child.end(); ++i)
    {
        if(*i == child)
            parent->child.erase(*i);
    }
}
template <class T>
void FibHeap<T>::RemoveRoot(fibHeapNode<T>* y, FibHeap<T>* heap)
{
    fibHeapNode<T>* left_y = y->left;
    fibHeapNode<T>* right_y = y->right;
    this->nnodes-=1;

    left_y->right = right_y;
    right_y->left = left_y;
}


template <class T>
fibHeapNode<T>* FibHeap<T>::DeleteMin(FibHeap<T>* heap)
{
    fibHeapNode<T>* min = heap->mini;
    if(min == nullptr)
    {
        return heap->mini;
    }

    for(int i = 0; i < min->child.size(); ++i)
    {
        heap->AddToRoot(min->child[i], heap);
        min->child[i]->parent = min->child[i];
    }

    min->child.clear();
    min->degree = 0;
    fibHeapNode<T>* left_bro = min->left;
    fibHeapNode<T>* right_bro = min->right;
    left_bro->right = right_bro;
    right_bro->left = left_bro;
    heap->nnodes-=1;

    if(min == min->right)
        heap->mini = nullptr;
    else
    {
        heap->mini = min->right;
        Consolidate(heap);
    }

    return min;

}

template <class T>
void FibHeap<T>::DecreasKey(FibHeap<T>* heap, fibHeapNode<T>* x, int new_key)
{
    if(new_key > x->key)
        return;
    x->key = new_key;
    fibHeapNode<T>* y = x->parent;
    if(y != nullptr && x->key < y->key)
    {
        Cut(heap, y, x);
        CascadingCut(heap, y);
    }

    if(x->key < heap->mini->key)
        heap->mini = x;
}

template <class T>
void FibHeap<T>::Cut(FibHeap<T>* heap, fibHeapNode<T>* x, fibHeapNode<T>* y)
{
    RemoveChild(y,x);
    y->parent = y;
    x->degree-=1;
    AddToRoot(y, heap);
    x->parent = nullptr;
    x->mark = false;
}

template <class T>
void FibHeap<T>::CascadingCut(FibHeap<T>* heap, fibHeapNode<T>* y)
{
    fibHeapNode<T>* parent = y->parent;
    if(parent == nullptr)
        return;
    if(y->mark == false)
        y->mark = true;
    else
    {
        Cut(heap, y, parent);
        CascadingCut(heap, parent);
    }

}

template <class T>
void FibHeap<T>::Delete(FibHeap<T>* heap, fibHeapNode<T>* x)
{
    heap->DecreasKey(heap, x, -10000000);
    heap->DeleteMin(heap);
}



int main()
{
    FibHeap<int> fib;
    FibHeap<int> fib2;
    fib.insert(12,1);
    fib.insert(11,4);
    fib.insert(8,2);
    fib2.insert(13,13);
    fib2.insert(2,14);
    fibHeapNode<int>* del =  new fibHeapNode<int>(11,4);
    FibHeap<int> new_heap = fib.Union(&fib, &fib2);
    new_heap.Delete(&new_heap,new_heap.mini->left);
    fibHeapNode<int>* nh = new_heap.DeleteMin(&new_heap);
    fibHeapNode<int>* nh2 = new_heap.DeleteMin(&new_heap);
    cout << new_heap.mini->key;
    return 0;
}