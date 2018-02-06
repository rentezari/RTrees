
/*!
 *  \brief     Tree.cpp
 *  \details   RTrees
 *  \date      2017
 */

#include "Tree.hpp"

#include "print.cpp"
#include "delete.cpp"
#include "add.cpp"
#include "find.cpp"
#include "count.cpp"
#include "grow.cpp"


template <typename Node, unsigned int default_cond, typename condition_type>
Tree<Node,default_cond,condition_type>::Tree()
{
    root = NULL;
    N_digits_printed = 1;
    output_format = None;
}

template <typename Node, unsigned int default_cond, typename condition_type>
Tree<Node,default_cond,condition_type>::~Tree()
{
    if(root!=NULL)
    {
        delete_branches(root);
        delete root;
        root = NULL;
    }
}
