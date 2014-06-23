#ifndef _AvlTree_h_
#define _AvlTree_h_

#include <stdexcept>

namespace trees {

template <class T> class AvlTree {

    struct node{
        node(const T& element):
            left{nullptr},
            right{nullptr},
            element{element},
            _height{1}    
        {}

    int height(node* _root) const
    {
    	if(_root == nullptr)
    	{
    		return 0;
    	}
    	return _root->_height;
    }

    int factor(node* _root) const
    {
    	if(_root == nullptr)
    	{
    		return 0;
    	}
    	return height(_root->left) - height(_root->right);
    }   

    void rightRotation(node*& _root) {
		node* aux;
		aux = _root->left;
		_root->left = aux->right;
		aux->right = _root;
		_root = aux;
	} 


	void leftRotation(node*& _root) {
		node* aux;
		aux = _root->right;
		_root->right = aux->left;
		aux->left = _root;
		_root = aux;
	}


    node* recursiveInsert(const T& added, node*& _root)
    {
        if(added < _root->element)
        {
            if(_root->left == nullptr)
            {
                _root->left = new node(added);
            }
            else
            {
                _root->left = recursiveInsert(added, _root->left);
                	if (factor(_root) == 2) 
                	{
                		if (factor(_root->left) == -1)
                		{
							leftRotation(_root->left);
						}
						rightRotation(_root);
					}
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
                _root->right = recursiveInsert(added, _root->right);
                	if (factor(_root) == -2) 
                	{
						if (factor(_root->right) == 1)
						{
							rightRotation(_root->right);
						}
						leftRotation(_root);
					}

            }
        }
        if(added == _root->element)
        {
           std::exception(); 
        }
        ++_root->_height;
        return _root;
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
       // If we find a nullptr, the item does not exist in this tree.
		if (_root == nullptr)
			throw std::exception();

		// The same of insertion works here. Find where the item must be, rebalance if needed.
		else if (removed < _root->element) 
			{
			_root->left = recursiveRemove(removed, _root->left);
			if (factor(_root) == 2) 
			{
				if (factor(_root->left) == -1)
				{
					leftRotation(_root->left);
				}
				rightRotation(_root);
			}
		} else if (removed > _root->element) 
			{
			_root->right = recursiveRemove(removed, _root->right);

			if (factor(_root) == -2) 
			{
				if (factor(_root->right) == 1)
				{
					rightRotation(_root->right);
				}
				leftRotation(_root);
			}
		}

		// If root's value is equal to removed value, we found the node to remove.
		else {

			// Leaf case: just delete the actual node.
			if (_root->left == nullptr && _root->right == nullptr) 
			{
				delete _root;
				return nullptr;
			}

			// If there is only right child, replace the to-be-deleted node and delete it.
			if (_root->left == nullptr) 
			{
				node* aux = _root->right;
				delete _root;
				return aux;
			}

			// If there is only left child, replace the to-be-deleted node and delete it.
			if (_root->right == nullptr) 
			{
				node* aux = _root->left;
				delete _root;
				return aux;
			}

			// If there are both children, find the immediately next value, swap and retry to remove.
			node* aux = findLeftmost(_root->right);
			_root->element = aux->element;
			_root->right = recursiveRemove(removed, _root->right);
		}

		// Recalculate the node height according to the removal.
		--_root->_height;
		return _root;
    }


        node* left;
        node* right;
        T element;
        int _height;
    };

public:

    AvlTree():
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
        root = root->recursiveRemove(removed, root); 
    }





private:
    node* root;
};

};


#endif