#ifndef _BinarySearchTree_h_
#define _BinarySearchTree_h_

namespace trees {

template <class T> class BinarySearchTree {

    struct node{
        node(const T& element):
            left{nullptr},
            right{nullptr},
            element{element}    
        {}

    void recursiveInsert(const T& added, node* _root)
    {
        if(added < _root->element)
        {
            if(_root->left == nullptr)
            {
                _root->left = new node(added);
            }
            else
            {
                recursiveInsert(added, _root->left);
            }
        }
        if(added > _root->element)
        {
            if(_root->right == nullptr)
            {
                _root->right = new node(added);
            }
            else
            {
                recursiveInsert(added, _root->right);
            }
        }
    }

        node* left;
        node* right;
        T element;
    };

public:
    BinarySearchTree():
        root{nullptr}
    {}

    node* rootForTest()
    {
        return root;
    }

    void insert(const T& added)
    {
        if(root == nullptr)
        {
            root = new node(added);
            return;
        }

        root->recursiveInsert(added, root);
    }

   

    bool has(const T& item)
    {
        if(root == nullptr) {
            return false;
        }

        node* aux = root;

        if(item == aux->element)
        {
            return true;
        }
        if(item < aux->element)
        {
            aux = aux->left;
        }
        else
        {
            aux = aux->right;
        }
        if(aux == nullptr)
        {
            return false;
        }

        return aux->element == item;
    }

    // T remove(const T& removed)
    // {
    //     if(root->right != nullptr)
    //     {
    //         auto aux = root->right->element;

    //         delete root->right;
    //         root->right = nullptr;
    //         return aux;
    //     }

    //     auto aux = root->element;

    //     delete root;
    //     root = nullptr;
    //     return aux;
    // }

private:
    node* root;
};

}

#endif