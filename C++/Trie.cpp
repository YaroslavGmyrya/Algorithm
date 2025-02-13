#include <iostream>
#include <vector>

using namespace std;


class str
{
    public:
    int Lenght;
    char* word;
    int lenght();
    void pop_back();
    void pop_front();
    int lenght_str(const char* word);
    void add(char c);
    void show();

    str()
    {
        word = nullptr;
    }

    str(const char* word)
    {
        Lenght = lenght_str(word);
        this->word = new char[Lenght + 1];

        for(int i = 0; i < Lenght; ++i)
        {
            this->word[i] = word[i]; 
        }

        this->word[Lenght] = '\0';
    }
};

int str::lenght()
{
    return Lenght;
}

void str::pop_back()
{
    if(Lenght < 1)
        return;
    char* tmp = new char[Lenght];

    for(int i = 0; i < Lenght - 1; ++i)
    {
        tmp[i] = word[i];
    }

    tmp[Lenght] = '\0';
    Lenght-=1;
    this->word = tmp;

    tmp = nullptr;
    delete tmp;
}

void str::pop_front()
{
    char* tmp = new char[Lenght];

    for(int i = 0; i < Lenght - 1; ++i)
    {
        tmp[i] = word[i+1];
    }

    tmp[Lenght] = '\0';
    Lenght-=1;
    this->word = tmp;

    tmp = nullptr;
    delete tmp;
}

 int str::lenght_str(const char* word)
{
    int i = 0;
    while(word[i] != '\0')
        i++;
    return i;
}

void str::show()
{
    for(int i = 0; i < Lenght; ++i)
        cout << word[i];
    cout << endl;
}

void str::add(char c)
{
    if(word == nullptr)
    {
        word = new char[1];
        word[0] = c;
        Lenght = 1;
    }
    else
    {
        char* new_word = new char[Lenght + 2];
        for(int i = 0; i < Lenght; ++i)
            new_word[i] = word[i];
        new_word[Lenght] = c;
        new_word[Lenght+1] = '\0';
        word = new_word;
        Lenght+=1;

        new_word = nullptr;
        delete new_word;
    }
    
}

template <class T>
class vect;

template<class KeyType>
struct Tnode
{
    KeyType value;
    char key;
    vect<KeyType> children;
    bool flag;

    Tnode(char key, KeyType value)
    {
        this->key = key;
        this->value = value;
        flag = false;
    }

    Tnode()
    {

    }
    
};

template <class T>
class vect
{
    public:
    Tnode<T>** arr;
    int size;

    vect()
    {
        size = 0;
        arr = nullptr;
    }

    void push_back(Tnode<T>* node)
    {
        if(arr == nullptr)
        {
            arr = new Tnode<T>*[1];
            arr[0] = node;
            size+=1;
        }

        else
        {
            Tnode<T>** tmp = new Tnode<T>*[size+1];
            for(int i = 0; i < size; i++)
                tmp[i] = arr[i];
            tmp[size] = node;

            arr = tmp;

            tmp = nullptr;
            delete [] tmp;
            size+=1;
        }
    }

    int len() {return size;}

    Tnode<T>*operator[](int i)
    {
        return arr[i];
    }
};

template <class T>
class Trie
{
    private:
      
        void trie_insert(str word, T value, Tnode<T>*& root);
        void trie_print(str word, Tnode<T>* root);
        void trie_delete(str word, Tnode<T>*& root);
        Tnode<T>* char_in_trie(Tnode<T>* root, char key);
        T trie_lookup(str word, Tnode<T>* root);
      
        
    public:
      Tnode<T>* root;
    Trie()
    {
        root = new Tnode('*', 0);
    }
    
    void trie_insert(str word, T value);
    void trie_print();
    void trie_delete(str word);
    T trie_lookup(str word);
};

template <class T>
void Trie<T>::trie_insert(str word, T value, Tnode<T>*& root)
{
        if(word.lenght() == 0)
            return;

        Tnode<T>* child = char_in_trie(root, word.word[0]);
        
        if(child == nullptr)
        {
            Tnode<T>* new_node = new Tnode(word.word[0], value);
            
            if(word.lenght() == 1)
            {
                new_node->flag = true;
                new_node->value = value;
            }

            root->children.push_back(new_node);
            word.pop_front();
            trie_insert(word, value, new_node);
        }

        else
        {
            word.pop_front();
            trie_insert(word, value, child);
        }
           

}
template <class T>
Tnode<T>* Trie<T>:: char_in_trie(Tnode<T>* root, char key)
        {
            for(int i = 0; i < root->children.len(); ++i)
            {
                if(root->children[i]->key == key)
                    return root->children[i];
            }

            return nullptr;
        }

template <class T>
void Trie<T>::trie_insert(str word, T value)
{
    trie_insert(word, value, root);
}

template <class T>
void Trie<T>::trie_print()
{
    str word;
    trie_print(word,root);
}

template <class T>
void Trie<T>::trie_print(str word, Tnode<T>* root)
{

    for (int i = 0; i < root->children.len(); ++i)
    {
        word.add(root->children[i]->key);
        
        if (!root->children[i]->flag)
        {
            trie_print(word, root->children[i]);
        }
        else
        {
            word.show();
            trie_print(word, root->children[i]);
        }

        word.pop_back(); // Удаляем последний символ после возврата из рекурс
    }

}

template <class T>
void Trie<T>:: trie_delete(str word)
{
    trie_delete(word, root);
}
template <class T>
void Trie<T>::trie_delete(str word, Tnode<T>*& root)
{
    Tnode<T>* child = char_in_trie(root,  word.word[0]);

    if(child == nullptr)
    {
        return;
    }

    else
    {
        if(word.lenght() != 1)
        {
            word.pop_front();
            trie_delete(word,child);
        }

        else
        {
            child->flag = false;
        }
        
    }
}

template <class T>
T Trie<T>::trie_lookup(str word)
{
    return trie_lookup(word, root);
}
template <class T>
T Trie<T>::trie_lookup(str word, Tnode<T>* root)
{
    Tnode<T>* child = char_in_trie(root, word.word[0]);
    if(child == nullptr)
        return -1;
    if(word.Lenght == 1)
        return child->value;

   word.pop_front();
   return trie_lookup(word, child);



}


int main()
{
    Trie<int> tr;
    str st1("aboba");
    str st2("biba");
    str st3("boba");
    str st4("Jake");

    tr.trie_insert(st1, 10);
    tr.trie_insert(st2, 11);
    tr.trie_insert(st3, 12);
    tr.trie_insert(st4, 14);
    tr.trie_print();

    str word;

    word.add('a');
    word.add('b');
    word.add('o');
    word.add('b');

    cout << word.word[3];
    

    return 0;
}