#include <iostream>

using namespace std;

const int t = 2;

class Bnode
{   public:
        bool leaf;
        int count;
        int keys[2*t-1];
        Bnode* child[2*t];

        Bnode(int key)
        {
            count = 0;
            keys[0] = key;
            leaf = true;
        }

        Bnode(){
            count = 0;
            leaf = true;
        }


};

class BTree
{
    public:
    Bnode* root = nullptr;
    Bnode* insert(Bnode*& root, int key);
    void split(Bnode *node, Bnode *parent, int index);
    Bnode* insert_nonfull(Bnode* node, int key);
    int GetKeyPos(Bnode* root, int key);
    void Delete(Bnode* root, int key);


    bool look_up(int key, Bnode* root, Bnode** parent = nullptr, Bnode** node = nullptr ,int* index = nullptr)
    {
        int i = GetKeyPos(root, key);
        if(i < root->count && root->keys[i] == key)
        {   
            *node = root;
            *index = i;
            return true;
        }
           

        if(root->leaf == true)
            return false;

        *parent = root;    
        return look_up(key, root->child[i], parent, node);
    }

};

int BTree::GetKeyPos(Bnode* root, int key)
{
    int i = 0;
    while(i < root->count && root->keys[i] < key)
        i++;
    return i;
}

Bnode* BTree::insert(Bnode*& root, int key)
{
    Bnode* newroot;
    if(root == NULL) {
    root = new Bnode(key);
    root->count++;
    root->leaf = true;
    return root;
    }
    if (root->count == 2 * t - 1) {
    Bnode* newroot = new Bnode(); /* Создание пустого корня */
    newroot->leaf = false;
    newroot->child[0] = root;
    split(root, newroot, 0);
    return insert_nonfull(newroot, key);
    }
    return insert_nonfull(root, key);
}

void BTree::split(Bnode *node, Bnode *parent, int index)
{
    int i;

    Bnode* z = new Bnode();
    z->leaf = node->leaf;
    z->count = t - 1;

    for (i = 0; i < t - 1; i++) {
    z->keys[i] = node->keys[t + i];
    }
    if (!node->leaf) {
    for (i = 0; i < t; i++)
    z->child[i] = node->child[i + t];
    }
    node->count = t - 1;

    /* Вставка медианного ключа в родительский узел */
    for (i = parent->count; i >= 0 && i <= index + 1; i--)
        parent->child[i + 1] = parent->child[i];

    parent->child[index + 1] = z;
    for (i = parent->count - 1; i >= 0 && i <= index; i--) {
    parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = node->keys[t - 1];
    parent->count++;

    root = parent;
    }

Bnode* BTree::insert_nonfull(Bnode* node, int key)
{
    int i;
    i = node->count;
    if (node->leaf) 
    {
    for (i = node->count - 1; i > 0 && key < node->keys[i]; i--) 
        node->keys[i + 1] = node->keys[i];
    
    node->keys[i + 1] = key;
    node->count++;
    } 

    else 
    {
    for (i = node->count - 1; i > 0 && key < node->keys[i]; )
        i--;

    i++;

    if (node->child[i]->count == 2 * t - 1) {
        split(node->child[i], node, i);

    if (key > node->keys[i])
        i++;
    }

    node = insert_nonfull(node->child[i], key);
    }

    return node;
}


void BTree::Delete(Bnode* root, int key)
{
    Bnode* parent;
    Bnode* node;
    int* child_pos;
    look_up(key,root,&parent, &node, child_pos);
    if(node == nullptr)
        return;
    if(node->leaf == true)
    {
        if(count <= t-1)
        {
            Bnode* left_bro = parent->child[*child_pos - 1];
            Bnode* right_bro = parent->child[*child_pos + 1];
            if(*child_pos != 0 && (left_bro->count > t-1))
            {
                int max_left_key = left_bro->keys[left_bro->count - 1];
                int separator = 0;
                int pos_seporator = 0;
                for(int i = 0; i < parent->count; i++)
                {
                    if(max_left_key < parent->keys[i])
                    {
                        separator = parent->keys[i];
                        pos_seporator = i;
                        break;
                    }
                }
            
                int tmp = parent->keys[pos_seporator];
                parent->keys[pos_seporator] = max_left_key;
                left_bro->count--;
                int delete_pos = GetKeyPos(node, key);
                node->keys[delete_pos] = tmp;
                //recovery node
            }

            else if(*child_pos == 0 && (right_bro->count > t-1))
            {
                int min_rigt_key = right_bro->keys[0];
                int separator = 0;
                int pos_seporator = 0;

                for(int i = 0; i < parent->count; i++)
                {
                    if(key < parent->keys[i])
                    {
                        separator = parent->keys[i];
                        pos_seporator = i;
                        break;
                    }
                }

                int tmp = parent->keys[pos_seporator];
                parent->keys[pos_seporator] = min_rigt_key;
                right_bro->count--;
                int delete_pos = GetKeyPos(node, key);
                node->keys[delete_pos] = tmp;
                //recovery right_bro
            }

            else
            {
                if(*child_pos == 0)
                {
                    Bnode* new_node;
                    int i = 0;
                    for(i; i < node->count; i++)
                        new_node->keys[i] = node->keys[i];
                    new_node->count += i;
                    for(int j = 0; j < right_bro->count; j++)
                        new_node->keys[i+j+1] = right_bro->keys[j];
                    new_node->count += j;

                    int delete_pos = GetKeyPos(new_node, key);

                    //recovery new_node

                    parent->child[*child_pos] = new_node;
                    parent->child[*child_pos-1] = nullptr;

                    //recovery parent->child
                }

                else
                {
                    Bnode* new_node;
                    int i = 0;
                    for(i; i < left_bro->count; i++)
                        new_node->keys[i] = left_bro->keys[i];
                    new_node->count += i;

                    for(int j = 0; j < node->count; j++)
                        new_node->keys[i+j+1] = node->keys[j];
                    new_node->count += j;

                    int delete_pos = GetKeyPos(new_node, key);

                    //recovery new_node

                    parent->child[*child_pos] = nullptr;
                    parent->child[*child_pos-1] = new_node;

                    //recovery parent->child
                    }
        }   }
    }

    else
    {
        
        int i = GetKeyPos(node, int key);
        
        for(i; i < node->count - 1; i++)
        {
            node->keys[i] = node->keys[i+1];
        }

        node->count--;        
        
    }


    else
    {
        
    }
    

}

int main()
{
    BTree btr;
    btr.insert(btr.root, 1);
    btr.insert(btr.root, 2);
    btr.insert(btr.root, 3);
    btr.insert(btr.root, 4);
    btr.insert(btr.root, 5);
    btr.insert(btr.root, 6);
    btr.insert(btr.root, 7);
    Bnode* parent;
    Bnode* node;
    btr.look_up(7,btr.root,&parent,&node);
    return 0;
}