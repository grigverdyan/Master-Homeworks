#include <iostream>
#include "binaryTree.h"

/*
        Tree structure
      
           A
       /        \
      B           C
     / \       /    \
    D   E     F        G
        /    |           \
      H     I                J

*/

int main()
{
    std::shared_ptr<BinaryTree<char>> tree = std::make_shared<NonEmptyNode<char>>(
        'A',
        std::make_shared<NonEmptyNode<char>>('B',
            std::make_shared<NonEmptyNode<char>>('D'),
            std::make_shared<NonEmptyNode<char>>('E',
                std::make_shared<NonEmptyNode<char>>('H'),
                std::make_shared<EmptyNode<char>>()
            )
        ),
        std::make_shared<NonEmptyNode<char>>('C',
            std::make_shared<NonEmptyNode<char>>('F',
                std::make_shared<NonEmptyNode<char>>('I'),
                std::make_shared<EmptyNode<char>>()
            ),
            std::make_shared<NonEmptyNode<char>>('G',
                std::make_shared<NonEmptyNode<char>>('J'),
                std::make_shared<EmptyNode<char>>()
            )
        )
    );
    
    std::cout << "Size of the tree: " << tree->size() << std::endl;
    std::cout << "Height of the tree: " << tree->height() << std::endl;
    std::cout << "Number of leaves in the tree: " << tree->numberOfLeaves() << std::endl;
    
    return 0;
}