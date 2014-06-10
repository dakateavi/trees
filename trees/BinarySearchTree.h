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

        node* left;
        node* right;
        T element;
    };

public:
    BinarySearchTree():
        root{nullptr}
    {}

    void insert(const T& added)
    {
        if(root == nullptr)
        {
            root = new node(added);
            return;
        }

        if(added < root->element){
            root->left = new node(added);
        }
        else {
            root->right = new node(added);
        }  
    }

    bool has(const T& item)
    {
        if(root == nullptr) {
            return false;
        }

        node* aux = root;

        if(item < aux->element) {
            aux = aux->left;
        }else{
            if(aux->element == item){
                return true;
            }else{
               aux = aux->right;
               if(aux == nullptr){
                return true;
               }

            }
        }

        return root->element == item;
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