
/*!
 *  \brief     grow.cpp
 *  \details   RTrees
 *  \date      2017
 */


#include "Tree.hpp"


template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::grow(condition_type j, condition_type j_bar)
{
    if(root!=NULL)
        grow(root, j, j_bar);
    else
    {
        root=new Node;
        *root = j;
        root->level = 0;
    }
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::grow(Node* node, condition_type j, condition_type j_bar)
{
    if(rand() % 2)
    {
        if(node->Right!=NULL)
        {
            grow(node->Right, j, j_bar);
        }
        else
        {
            node->Right = new Node;
            *(node->Right) = j;
            node->Right->level = node->level+1;
        }
    }
    else
    {
        if(node->Left!=NULL)
        {
            grow(node->Left, j, j_bar);
        }
        else
        {
            node->Left = new Node;
            *(node->Left) = j;
            node->Left->level = node->level+1;
        }
    }
}
