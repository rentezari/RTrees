
/*!
 *  \brief     deleter.cpp
 *  \details   RTrees
 *  \date      2017
 */


#include "Tree.hpp"


template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::delete_branches(Node *node)
{
    if(node!=NULL)
    {
        if(node->Left!=NULL)
        {
            delete_branches(node->Left);
            node->Left=NULL;
        }
        
        if(node->Right!=NULL)
        {
            delete_branches(node->Right);
            node->Right=NULL;
        }
    }
}
