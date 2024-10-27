#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <algorithm>
#include <memory>

template <typename T>
class BinaryTree
{
public:
    virtual int size() const = 0;
    virtual int height() const = 0;
    virtual int numberOfLeaves() const = 0;
    virtual ~BinaryTree() = default;
};

template <typename T>
class EmptyNode : public BinaryTree<T>
{
public:
    int size() const override { return 0; }
    int height() const override { return 0; }
    int numberOfLeaves() const override { return 0; }
};

template <typename T>
class NonEmptyNode : public BinaryTree<T> 
{
private:
    T root;
    std::shared_ptr<BinaryTree<T>> leftSubtree;
    std::shared_ptr<BinaryTree<T>> rightSubtree;
public:
    NonEmptyNode(T rootValue, std::shared_ptr<BinaryTree<T>> left = std::make_shared<EmptyNode<T>>(),
             std::shared_ptr<BinaryTree<T>> right = std::make_shared<EmptyNode<T>>())
        : root(rootValue)
        , leftSubtree(left)
        , rightSubtree(right)
    {}

    int size() const override 
    {
        return leftSubtree->size() + rightSubtree->size() + 1;
    }

    int height() const override
    {
        return std::max(leftSubtree->height(), rightSubtree->height()) + 1;
    }

    int numberOfLeaves() const override 
    {
        if (leftSubtree->size() == 0 && rightSubtree->size() == 0)
        {
            return 1;
        }
        return leftSubtree->numberOfLeaves() + rightSubtree->numberOfLeaves();
    }
};

#endif /* BINARY_TREE_H */