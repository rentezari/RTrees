
/*! \mainpage RTrees
 * \section intro_sec Introduction
 *
 * \section install_sec Installation
 *
 * \subsection
 */

/*!
 *  \brief     main.cpp
 *  \details   RTrees
 *  \date      2017
 */

#include "main.hpp"
#include "Tree.cpp"
#include <RInside.h>




int main(int argc, char * argv[])
{
    std::cout << "Start..." << std::endl;
    
    //For using R functions. It also seeds the random function for the rest of program.
    RInside R;
    //For example:
    Rcpp::NumericVector result = Rcpp::rnorm(2);
    std::cout << result << std::endl;
    std::cout << Rcpp::rnorm(2) << std::endl;
    
    //Creates a Tree instance using Tree<Node,0,int>: Node is the node structure to be used
    //as members of the tree. 0 sets the default member in the array "condition" inside
    //nodes. This can be reprogrammed by changing the definition of Node. int is the
    //type of the condition array inside node, ccan be int, unsigned int, float, double, long double,...
    //Node<1,int,0>: 1 is the size of array of conditions in each node, 1 meaning it only has one element
    // and so the default condition can only be the 0th member of the condition array.
    //int is the type and has to be the same as the one defined for Tree, this call can get packed into one function
    //or wrapper class to avoid repetitions.
    Tree<Node<1,int,0>,0,int> tree;
    
    //Preciosn of the numbers to be printed out
    tree.set_print_precision(1);
    
    //No print, or print on screen or print to Latex file, or a combination of Screen or Latex
    tree.set_output_format((print_format)(print_format::Screen | print_format::Latex));
    
    //adding nodes
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(1);
    tree.add(2);
    
    //prints the entire tree
    tree.print();
    
    //printing a portion of the tree
    tree.print(tree.find(3));
    
    //deleting a portion of the tree, here we find the first 3 under some conditions and delete what is beneath it
    tree.delete_branches(tree.find(3));
    
    //prints the entire tree
    tree.print();
    
    //adds a node starting from another node. here the find command returns the address of the node tha add command will
    //start the add process from it.
    tree.add(8, tree.find(3));
    
    //prints the entire tree
    tree.print();
    
    //deletes the tree instance
    tree.~Tree();
    
    //this how the deleted instance can be recycled to create a new instance after delete
    tree = *new Tree<Node<1,int,0>,0,int>;
    
    //Preciosn of the numbers to be printed out
    tree.set_print_precision(1);
    
    //No print, or print on screen or print to Latex file, or a combination of Screen or Latex
    tree.set_output_format((print_format)(print_format::Screen | print_format::Latex));
    
    //Growing tree members, rules can be changed
    for(int i=3;i<20;i++)
        tree.grow(i%10,3);
    
    //prints the entire tree
    tree.print();
    
    //deletes the tree instance
    tree.~Tree();
    
    std::cout << "End." << std::endl;
    
    return 0;
}
