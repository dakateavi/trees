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

    node* findLeftmost(node*& _root) 
    {
        node* curr = _root;
        while (curr->left)
            curr = curr->left;
        return curr;
    }

    node* recursiveRemove(const T& removed, node*& _root) 
    {
        if (_root == nullptr)
            return _root;
        if (removed < _root->element) {
            _root->left = recursiveRemove(removed, _root->left);
            return _root;
        }
        if (removed > _root->element) {
            _root->right = recursiveRemove(removed, _root->right);
            return _root;
        }
        if (_root->left && _root->right) {
            node* succ = findLeftmost(_root->right);
            _root->element = succ->element;
            _root->right = recursiveRemove(element, _root->right);
            return _root;
        }
        if (_root->left)
            return _root->left;
        if (_root->right)
            return _root->right;
        delete _root;
        return 0;
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

    void remove(const T& removed)
    {
        root->recursiveRemove(removed, root); 
    }





private:
    node* root;
};

}

#endif