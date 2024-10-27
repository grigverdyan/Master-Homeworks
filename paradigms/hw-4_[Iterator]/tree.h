#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "iterator.h"
#include <iostream>

class Tree
{
private:
    Node* root;
public:
    Tree()
        : root(nullptr)
    {}

    Tree(Node* rt)
        : root(std::move(rt))
    {}

    Node* getRoot()
    {
        return root;
    }

    void addLeftChild(Node* parent, Node* child)
    {
        parent->left = child;
    }

    void addRightChild(Node* parent, Node* child)
    {
        parent->right = child;
    }

    Iterator* createIterator(Iterator* it)
    {
        return it->clone(root);
    }
};

#endif /* TREE_H */