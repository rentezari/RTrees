
/*!
 *  \brief     main.hpp
 *  \details   RTrees
 *  \date      2017
 */

#ifndef main_hpp
#define main_hpp

#include <iostream>


/** @brief Structure defining each node in the tree.
 *  @details
 *  Usage: Use <tt>Node<1,int,0></tt>.
 *  @tparam N Size of the \p condition array.
 *  @tparam default_cond The default condition in the array of conditions.
 *  @tparam condition_type Type of the condition array and values, i.e., int, float, double, ...
 */
template <int N, typename condition_type, unsigned int default_cond>
struct Node
{
    condition_type condition[N] = {0}; /*!< Array of conditions, size defined by \p N. */
    unsigned int condition_size = N; /*!< Size of the \p condition array. */
    unsigned int level = 0; /*!<  Level at which this node is located. */
    Node *Left = NULL; /*!<  Address to the left child node. */
    Node *Right = NULL; /*!<  Address to the right child node. */
    
    /** Constrcutor I.
     */
    Node(){}
    
    /** Constrcutor II:
     *  Sets the element located at \p condtion[\p default_cond] to an initial value.
     *  @param[in] initial_condition Initial condition for the member of condition array sitting in default location.
     */
    Node(condition_type initial_condition)
    {
        condition[default_cond] = initial_condition;
    }
    
    /** Operator setting a condition value to \p condtion[\p default_cond]
     *  @param[in] value The condition value.
     */
    void operator=(const condition_type& value)
    {
        condition[default_cond]=value;
    }
    
    /** Operator checks equality of the condition value to \p condtion[\p default_cond]
     *  @param[in] value The condition value.
     *  @return If the \p condtion[\p default_cond] is equal to the inputted value.
     */
    bool operator==(const condition_type& value) const
    {
        return (condition[default_cond]==value);
    }
    
    /** Operator checks if \p condtion[\p default_cond] is larger than or equal to the value.
     *  @param[in] value The condition value.
     *  @return If the \p condtion[\p default_cond] is larger than or equal to the inputted value.
     */
    bool operator>=(const condition_type& value) const
    {
        return (condition[default_cond]>=value);
    }
    
    /** Operator checks if \p condtion[\p default_cond] is smaller than or equal to the value.
     *  @param[in] value The condition value.
     *  @return If the \p condtion[\p default_cond] is smaller than or equal to the inputted value.
     */
    bool operator<=(const condition_type& value) const
    {
        return (condition[default_cond]<=value);
    }
    
    /** Operator checks if \p condtion[\p default_cond] is larger than the value.
     *  @param[in] value The condition value.
     *  @return If the \p condtion[\p default_cond] is larger than the inputted value.
     */
    bool operator>(const condition_type& value) const
    {
        return (condition[default_cond]>value);
    }
    
    /** Operator checks if \p condtion[\p default_cond] is smaller than the value.
     *  @param[in] value The condition value.
     *  @return If the \p condtion[\p default_cond] is smaller than the inputted value.
     */
    bool operator<(const condition_type& value) const
    {
        return (condition[default_cond]<value);
    }
};


#endif /* main_hpp */
