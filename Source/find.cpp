
/*!
 *  \brief     find.cpp
 *  \details   RTrees
 *  \date      2017
 */


#include "Tree.hpp"


template <typename Node, unsigned int default_cond, typename condition_type>
Node* Tree<Node,default_cond,condition_type>::find(Node *node, condition_type value)
{
    if(node!=NULL)
    {
        if(*node == value)
            return node;
        if (*node < value)
            return find(node->Right, value);
        else
            return find(node->Left, value);
    }
    return NULL;
}

template <typename Node, unsigned int default_cond, typename condition_type>
Node* Tree<Node,default_cond,condition_type>::find(condition_type value)
{
    if(root!=NULL)
    {
        if(*root == value)
            return root;
        if (*root < value)
            return find(root->Right, value);
        else
            return find(root->Left, value);
    }
    return NULL;
}
