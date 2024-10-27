#include <iostream>
#include <memory>
#include "iterator.h"
#include "tree.h"

void printTraversal(Tree& aggregate, Iterator* it)
{
    it = aggregate.createIterator(std::move(it));

    for (it->first(); !it->isDone(); it->next())
    {
        std::cout << it->currentItem() << " ";
    }
    std::cout << std::endl;
}

int main()
{    
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');

    Tree tree(A);
    tree.addLeftChild(A, B);
    tree.addRightChild(A, C);
    tree.addLeftChild(B, D);
    tree.addRightChild(B, E);
    tree.addLeftChild(C, F);
    tree.addRightChild(C, G);
    tree.addLeftChild(D, H);
    tree.addRightChild(D, I);
    tree.addLeftChild(E, J);

    std::cout << "Preorder Traversal: ";
    Iterator* preorderIterator = tree.createIterator(new PreorderIterator(tree.getRoot()));
    printTraversal(tree, preorderIterator);

    std::cout << "Inorder Traversal: ";
    Iterator* inorderIterator = tree.createIterator(new InorderIterator(tree.getRoot()));
    printTraversal(tree, inorderIterator);

    delete preorderIterator;
    delete inorderIterator;
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete G;
    delete H;
    delete I;
    delete J;

    return 0;
}
