#ifndef _BinaryTree_h_
#define _BinaryTree_h_

namespace trees {

template <class T> class BinaryTree {

    struct node{
        node(const T& element):
            left(nullptr),
            right(nullptr),
            element(element)
        {}

        node* left;
        node* right;
        T element;
    };

public:
    BinaryTree():
        root(nullptr)
    {}

    void insert(const T& added)
    {
        root = new node{added};
    }

    T remove(const T& removed)
    {
        T aux = root->element;

        delete root;
        return aux;
    }

private:
    node* root;
};

}

#endif