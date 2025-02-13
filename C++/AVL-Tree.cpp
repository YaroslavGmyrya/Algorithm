#include <iostream>

using namespace std;

template <class V, class K>
class Node
{
    public:
        V value;
        K key;
        int height;
        Node* left;
        Node* right;

        Node()
        {
            height = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(V value, K key) : Node()
        {
            this->value = value;
            this->key = key;
        }
};

template <class V, class K>
class AVL_T 
{
    public:
        Node<V,K>* root;

        AVL_T()
        {
            root = nullptr;
        }

        AVL_T(V value, K key)
        {
            root = new Node(value, key);
        }

        
        void Free();
        Node<V,K>* lookup(K key);
        void insert(Node<V,K>*& node, V value, K key);
        void insert(V value, K key);

    private:
        void RRotate(Node<V,K>* node);
        void LRotate(Node<V,K>*& node);
        void LRRotate(Node<V,K>* node);
        void RLRotate(Node<V,K>* node);
        int imax(int a, int b);
        void Free(Node<V,K>* root);
        Node<V,K>* lookup(K key, Node<V,K>* root);
        int height(Node<V,K>* node);
        int balance(Node<V,K>* node);
};

template <class V, class K>
void AVL_T<V,K>::Free(Node<V,K>* root)
{
    if(root = nullptr)
        return;
    free(root->left);
    free(root->right);
    root = nullptr;
    delete root;
}

template <class V, class K>
void AVL_T<V,K>::Free()
{
    Free(root);
}

template <class V, class K>
Node<V,K>* AVL_T<V,K>::lookup(K key, Node<V,K>* root)
{
    while(root != nullptr)
    {
        if(key == root->key)
            return root;
        else if(key < root->key)
            root = root->left;
        else
        {
            root = root->right;
        }
    }

    return root;
}

template <class V, class K>
Node<V,K>* AVL_T<V,K>::lookup(K key)
{
    return lookup(key,root);
}


template <class V, class K>
int AVL_T<V,K>::height(Node<V,K>* node)
{
    return (node != nullptr) ? node->height : 1;
}

template <class V, class K>
int AVL_T<V,K>::balance(Node<V,K>* node)
{
    return height(node->left) - height(node->right);
}

template <class V, class K>
void AVL_T<V,K>::insert(V value, K key)
{
    insert(root,value, key);
}

template <class V, class K>
void AVL_T<V,K>::insert(Node<V,K>*& node, V value, K key)
{
    if(node == NULL)
    {
        node = new Node<V,K>(value,key);
        return;
    }

    if(key < node->key)
    {
        insert(node->left, value, key);

        if(height(node->left) - height(node->right) == 2)
        {
            if(key < node->left->key)
                RRotate(node);
            else
                LRRotate(node);
        }
    }

    else if(key > node->key)
    {
        insert(node->right, value, key);

        if(height(node->right) - height(node->left) == 2)
        {
            if(key > node->right->key)
                LRotate(node);
            else
                RLRotate(node);
        }
    }

    node->height = imax(height(node->left), height(node->right)) + 1;  
}

template <class V, class K>
void AVL_T<V,K>::RRotate(Node<V,K>* node)
{
    Node<V,K>* tmp = node->left;

    node->left = tmp->right;
    tmp->right = node;

    node->height = imax(height(node->left), height(node->right)) + 1;
    tmp->height = imax(height(tmp->left), node->height) + 1;
    root = tmp;
}

template <class V, class K>
void AVL_T<V,K>::LRotate(Node<V,K>*& node)
{
    Node<V,K>* tmp = node->right;

    node->right = tmp->left;
    tmp->left = node;

    node->height = imax(height(node->left), height(node->right)) + 1;
    tmp->height = imax(height(tmp->right), node->height) + 1;
    root = tmp;
}

template <class V, class K>
void AVL_T<V,K>::LRRotate(Node<V,K>* node)
{
    LRotate(node);
    RRotate(node);
}

template <class V, class K>
void AVL_T<V,K>::RLRotate(Node<V,K>* node)
{
    RRotate(node);
    LRotate(node);
}

template <class V, class K>
int AVL_T<V,K>::imax(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    AVL_T<int,int> tree;
    tree.insert(10,10);
    tree.insert(9,9);
    tree.insert(8,8);
    tree.insert(7,7);
    Node<int,int>* tmp = tree.lookup(8);
    cout << tmp->value << endl << tmp->key << endl;
    return 0;
}