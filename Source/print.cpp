

/*!
 *  \brief     print.cpp
 *  \details   RTrees
 *  \date      2017
 */

#include "Tree.hpp"
#include <iomanip>
#include <fstream>
#include <math.h>


template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::set_print_precision(unsigned int _N_digits_printed)
{
    N_digits_printed = _N_digits_printed;
    std::cout << std::fixed;
    std::cout << std::setprecision(N_digits_printed);
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::set_output_format(print_format _output_format)
{
    output_format = _output_format;
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print()
{
    if(output_format & Screen)
        print_branch(root);
    
    if(output_format & Latex)
    {
        std::cout << "Writing Latex file: Latex_print.tex...";
        std::ofstream Latex_print_file ("Latex_print.tex");
        print_Latex_begin(&Latex_print_file);
        print_Latex_branch(root, &Latex_print_file);
        print_Latex_end(&Latex_print_file);
        Latex_print_file.close();
        std::cout << "   Done." << std::endl;
    }
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print(Node *node)
{
    if(output_format & Screen)
        print_branch(node);
    
    if(output_format & Latex)
    {
        std::cout << "Writing Latex file: Latex_print.tex...";
        std::ofstream Latex_print_file ("Latex_print.tex");
        print_Latex_begin(&Latex_print_file);
        print_Latex_branch(node, &Latex_print_file);
        print_Latex_end(&Latex_print_file);
        Latex_print_file.close();
        std::cout << "   Done." << std::endl;
    }
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print_Latex_begin(std::ofstream *Latex_print_file)
{
    if ((*Latex_print_file).is_open())
    {
        *Latex_print_file << "\\documentclass[landscape]{article}\\usepackage{tikz-qtree}\\tikzset{every tree node/.style={minimum width=2em,draw,circle},blank/.style={draw=none},edge from parent/.style={draw, edge from parent path={(\\tikzparentnode) -- (\\tikzchildnode)}}}\\begin{document}\\begin{center}\\resizebox{\\textheight}{!}{\\begin{tikzpicture}\\Tree" << std::endl;;
    }
    else
        std::cout << "Unable to write to Latex_print.tex" << std::endl;
    
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print_Latex_end(std::ofstream *Latex_print_file)
{
    if ((*Latex_print_file).is_open())
    {
        *Latex_print_file << "\\end{tikzpicture}}\\end{center}\\end{document}" << std::endl;;
    }
    else
        std::cout << "Unable to write to Latex_print.tex" << std::endl;
    
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print_Latex_branch(Node *node, std::ofstream *Latex_print_file)
{
    *Latex_print_file << "[";
    
    if(node!=NULL)
    {
        *Latex_print_file << "." << node->condition[default_cond] << " ";
        
        if(node->Left!=NULL)
        {
            print_Latex_branch(node->Left, Latex_print_file);
        }
        else
            *Latex_print_file << "N ";
        
        if(node->Right!=NULL)
        {
            print_Latex_branch(node->Right, Latex_print_file);
        }
        else
            *Latex_print_file << "N ";
    }
    else
        *Latex_print_file << "N ";
    
    *Latex_print_file << "]";
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print_a_level(unsigned int level, unsigned int max_level, Node *node)
{
    if(node->level==level)
    {
        std::cout << node->condition[default_cond];
        for(int j=0; j<(pow(2,(max_level-level+1))-1); j++)
            for(int k=0; k<N_digits_printed; k++)
                std::cout << " ";
    }
    
    if(node->Left!=NULL)
        print_a_level(level, max_level, node->Left);
    else if(node->level<=level-1 && level>0)
        for(int i=0; i< pow(2,(level-node->level-1)); i++)
        {
            for(int k=0; k<N_digits_printed/2; k++)
                std::cout << " ";
            std::cout << "N";
            for(int k=0; k<N_digits_printed/2; k++)
                std::cout << " ";
            for(int j=0; j<(pow(2,(max_level-level+1))-1); j++)
                for(int k=0; k<N_digits_printed; k++)
                    std::cout << " ";
        }
    
    if(node->Right!=NULL)
        print_a_level(level, max_level, node->Right);
    else if(node->level<=level-1 && level>0)
        for(int i=0; i< pow(2,(level-node->level-1)); i++)
        {
            for(int k=0; k<N_digits_printed/2; k++)
                std::cout << " ";
            std::cout << "N";
            for(int k=0; k<N_digits_printed/2; k++)
                std::cout << " ";
            for(int j=0; j<(pow(2,(max_level-level+1))-1); j++)
                for(int k=0; k<N_digits_printed; k++)
                    std::cout << " ";
        }
}

template <typename Node, unsigned int default_cond, typename condition_type>
void Tree<Node,default_cond,condition_type>::print_branch(Node *node)
{
    if(node!=NULL)
    {
        unsigned int max_level = 0;
        unsigned int local_level = node->level;
        max_level = count_levels(node, max_level);
        std::cout << "Levels: " << max_level-local_level+1 << std::endl;
        
        for(unsigned int i=local_level; i<=max_level; i++)
        {
            for(int j=0; j<=(pow(2,(max_level-i))-1); j++)
                for(int k=0; k<N_digits_printed; k++)
                    std::cout << " ";
            print_a_level(i, max_level, node);
            std::cout << std::endl;
            
            if(i!=max_level)
            {
                for(int j=0; j<=(pow(2,(max_level-i)) - int(pow(2,(max_level-i-1))-1)/2 -2); j++)
                    for(int k=0; k<N_digits_printed; k++)
                        std::cout << " ";
                for(int j=0; j<pow(2,(i-local_level)); j++)
                {
                    for(int k=0; k<N_digits_printed/2; k++)
                        std::cout << " ";
                    std::cout << "/";
                    for(int k=0; k<N_digits_printed/2; k++)
                        std::cout << " ";
                    for(int j=0; j<(int(pow(2,(max_level-i-1))-1)+(i==max_level-1)); j++)
                        for(int k=0; k<N_digits_printed; k++)
                            std::cout << " ";
                    for(int k=0; k<N_digits_printed/2; k++)
                        std::cout << " ";
                    std::cout << "\\";
                    for(int k=0; k<N_digits_printed/2; k++)
                        std::cout << " ";
                    for(int j=0; j<(pow(2,(max_level-i+1)) - int(pow(2,(max_level-i-1+1))-1)/2 -2-(i==max_level-1)); j++)
                        for(int k=0; k<N_digits_printed; k++)
                            std::cout << " ";
                }
                std::cout << std::endl;
            }
        }
    }else
        std::cout << "Print: Nothing to print! (NULL node)" << std::endl;
}
