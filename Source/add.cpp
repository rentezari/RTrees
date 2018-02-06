
/*!
 *  \brief     add.cpp
 *  \details   RTrees
 *  \date      2017
 */


#include "Tree.hpp"


template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::add(condition_type condition)
{
    if(root!=NULL)
        add(condition, 0, root);
    else
    {
        root=new Node;
        *root = condition;
        root->level = 0;
    }
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::add(condition_type condition, Node *node)
{
    if(node!=NULL)
    {
        add(condition, node->level, node);
    }
    else
    {
        std::cout << "Add: NULL Input!" << std::endl;
    }
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::add(condition_type condition, unsigned int level, Node *node)
{
    if(node!=NULL)
    {
        if (*node <= condition)
        {
            if(node->Right!=NULL)
            {
                add(condition, level+1, node->Right);
            }
            else
            {
                node->Right = new Node;
                *(node->Right) = condition;
                node->Right->level = level+1;
            }
        }
        else
        {
            if(node->Left!=NULL)
            {
                add(condition, level+1, node->Right);
            }
            else
            {
                node->Left = new Node;
                *(node->Left) = condition;
                node->Left->level = level+1;
            }
        }
    }
    else
    {
        std::cout << "Add: NULL Input!" << std::endl;
    }
}
