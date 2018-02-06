
/*!
 *  \brief     Tree.hpp
 *  \details   RTrees
 *  \date      2017
 */

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>

/** print_format enum type.
 *  User passing output formats.
 */
typedef enum {
    None =   1 << 0,  /**< No print */
    Screen = 1 << 1,  /**< Print Tree on screen */
    Latex =  1 << 2   /**< Print Tree to Latex file */
} print_format;


/** @brief Tree class: Class containing tree root and functions for modification
 *  and generation of tree
 *  @details
 *  Usage: Use <tt>Tree<Node,0,int></tt>.
 *  @tparam Node Defined the node types.
 *  @tparam default_cond The default condition in the array of conditions.
 *  @tparam condition_type Type of the condition array and values, i.e., int, float, double, ...
 */
template <typename Node, unsigned int default_cond, typename condition_type>
class Tree
{
public:
    /** Class constrcutor:
     *  Sets \p root to NULL.
     */
    Tree();
    
    /** Class destructor:
     *  Removes all branches and resets \p root to NULL.
     */
    ~Tree();
    
    /** Add Function I:
     *  Adds tree nodes.
     *  @param[in] condition Value of the condition.
     */
    void add(condition_type condition);
    
    /** Add Function II:
     *  Adds tree nodes.
     *  @param[in] condition Value of the condition.
     *  @param[in] node A node in the tree.
     */
    void add(condition_type condition, Node *node);
    
    /** Print function I:
     *  Prints entire tree starting from the \p root.
     */
    void print();
    
    /** Print function II:
     *  Prints all branches below a node.
     *  @param[in] node A node in the tree.
     */
    void print(Node *node);
    
    /** Changes the value for the number of decimal points to be printed.
     *  by the std::cout functions. Also controls the 
     *  spaces in tree branch visualizations.
     *  @param[in] _N_digits_printed User input for the number of decimal points to be printed.
     */
    void set_print_precision(unsigned int _N_digits_printed);
    
    /** Finds the first node that matches the condition.
     *  @param[in] value The condition value to be found in the nodes.
     *  @return The address to the node with matching condition.
     */
    Node* find(condition_type value);
    
    /** Grow function I:
     *  Grows branches by adding a new node using random paths.
     *  @param[in] j The condition value to be added as a new node.
     *  @param[in] j_bar The deciding condition.
     */
    void grow(condition_type j, condition_type j_bar);
    
    /** Grow function II:
     *  Grows branches by adding a new node using random paths.
     *  @param[in] node Defines the starting point the grow process.
     *  @param[in] j The condition value to be added as a new node.
     *  @param[in] j_bar The deciding condition.
     */
    void grow(Node *node, condition_type j, condition_type j_bar);
    
    /** Deletes branches below a specific node.
     *  @param[in] node Branches below this node will be deleted (this node itself is not deleted).
     */
    void delete_branches(Node *node);
    
    /** Sets the format of the output to none, or on screen, or in Latex, or both.
     *  @param[in] _output_format Format of the output chosen from print_format \p enum.
     */
    void set_output_format(print_format _output_format);

private:
    
    Node *root; /*!< The root of the tree, lowest node and located at level 0 */
    
    unsigned int N_digits_printed;  /*!< Number of decimal points to be printed, default is 1. */
    
    print_format output_format;
    
    /** Add Function III:
     *  Adds tree nodes.
     *  @param[in] condition Value of the condition.
     *  @param[in] level Integer showing the level at which the new node is being added.
     *  @param[in] node A node in the tree.
     */
    void add(condition_type condition, unsigned int level, Node *node);
    
    /** Counts level below a node.
     *  @param[in] node A node in the tree.
     *  @param[in] max_level The value of maximum level number found so far.
     *  @return Returns the maximum level value found below the branch the function was called upon.
     */
    unsigned int count_levels(Node *node, unsigned int max_level);
    
    /** Private function called by public print functions.
     *  Prints branches below a node.
     *  @param[in] node A node in the tree.
     */
    void print_branch(Node *node);
    
    /** Initiates the Latex file
     *  @param[in] Latex_print_file Pointer to opened file.
     */
    void print_Latex_begin(std::ofstream *Latex_print_file);
    
    /** Prints all branches below a node into the Latex file.
     *  @param[in] node A node in the tree.
     *  @param[in] Latex_print_file Pointer to opened file.
     */
    void print_Latex_branch(Node *node, std::ofstream *Latex_print_file);
    
    /** Closes the Latex file
     *  @param[in] Latex_print_file Pointer to opened file.
     */
    void print_Latex_end(std::ofstream *Latex_print_file);
    
    /** Private function called by private function print_branch.
     *  Prints all nodes that are located on the same level.
     *  @param[in] level The level that is being printed.
     *  @param[in] node A node in the tree.
     *  @param[in] max_level Maximum level number.
     */
    void print_a_level(unsigned int level, unsigned int max_level, Node *node);
    
    /** Private function called by public find function.
     *  Finds the first node matching to the condition.
     *  @param[in] node A node in the tree.
     *  @param[in] value The condition value to be found in the nodes.
     *  @return The address to the node with matching condition.
     */
    Node* find(Node *node, condition_type value);
};

#endif /* Tree_hpp */
