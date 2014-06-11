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

    void recursiveInsert(const T& added, node*& _root)
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

    node*& rootForTest()
    {
        return root;
    }

    node* findLeftmost(node*& _root) {
        node* curr = _root;
        while (curr->left)
            curr = curr->left;
        return curr;
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

    node* recursiveRemove(const T& removed, node*& _root) {
        if (_root == nullptr)
            return root;
        if (removed < _root->element) {
            root->_left = remove(removed, root->left);
            return root;
        }
        if (removed > root->element) {
            root->_right = remove(removed, root->right);
            return root;
        }
        if (root->left && root->right) {
            node* aux = find_leftmost(root->right);
            root->element = aux->element;
            root->right = remove(removed, root->right);
            return root;
        }
        if (root->left)
            return root->left;
        if (root->right)
            return root->right;
        delete _root;
        return 0;
    }



private:
    node* root;
};

}

#endif