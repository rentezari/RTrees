
/*!
 *  \brief     count.cpp
 *  \details   RTrees
 *  \date      2017
 */

#include "Tree.hpp"


template <typename Node, unsigned int default_cond, typename condition_type>
unsigned int Tree<Node,default_cond,condition_type>::count_levels(Node *node, unsigned int max_level)
{
    max_level = std::max(max_level, node->level);
    
    if(node->Left!=NULL)
        max_level = std::max(max_level, count_levels(node->Left, max_level));
    
    if(node->Right!=NULL)
        max_level = std::max(max_level, count_levels(node->Right, max_level));
    
    return (max_level);
}
