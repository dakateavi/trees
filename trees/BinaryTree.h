#ifndef _BinaryTree_h_
#define _BinaryTree_h_

namespace trees {

template <class T> class BinaryTree {

    struct node{
        node(const T& element):
            left{nullptr},
            right{nullptr},
            element{element}    
        {}

        node* left;
        node* right;
        T element;
    };

public:
    BinaryTree():
        root{nullptr}
    {}

    void insert(const T& added)
    {
        if(root == nullptr)
        {
            root = new node(added);
            return;
        }
        if(added < root->element)
        {
        root->right = new node(added);
        }
    }

    T remove(const T& removed)
    {
        if(root->right != nullptr)
        {
            auto aux = root->right->element;

            delete root->right;
            root->right = nullptr;
            return aux;
        }


        auto aux = root->element;

        delete root;
        root = nullptr;
        return aux;
    }

private:
    node* root;
};

}

#endif