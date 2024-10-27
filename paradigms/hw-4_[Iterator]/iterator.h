#ifndef ITERATOR_H
#define ITERATOR_H

#include <stack>
#include "node.h"

class Iterator
{
protected:
    std::stack<Node*> stack;
    Node* current;
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual char currentItem() = 0;
    virtual Iterator* clone(Node* root) = 0;
    virtual ~Iterator() = default;
};

class PreorderIterator : public Iterator
{
private:
    Node* tree;
public:
    PreorderIterator(Node* root) 
        : tree(root)
    {}

    void first() override
    {
        while (!stack.empty())
        {
            stack.pop();
        }
        current = tree;
    }

// smth wrong
    void next() override
    {
        if (current->left)
        {
            if (current->right)
            {
                stack.push(current->right);
            }
            current = current->left;
        } 
        else if (current->right)
        {
            current = current->right;
        } 
        else if (!stack.empty())
        {
            current = stack.top();
            stack.pop();
        } 
        else
        {
            current = nullptr;
        }
    }

    bool isDone() override
    {
        return current == nullptr;
    }

    char currentItem() override
    {
        return current->data;
    }

    Iterator* clone(Node* root) override
    {
        return new PreorderIterator(root);
    }
};

class InorderIterator : public Iterator
{
private:
    Node* tree;
public:
    InorderIterator(Node* root) 
        : tree(root)
    {}

    void first() override
    {
        current = tree;
        while (current)
        {
            stack.push(current);
            current = current->left;
        }
        if (!stack.empty())
        {
            current = stack.top();
            stack.pop();
        }
    }

// neeed to revisit
    void next() override
    {
        if (current->right)
        {
            current = current->right;
            while (current)
            {
                stack.push(current);
                current = current->left;
            }
        }
        if (!stack.empty())
        {
            current = stack.top();
            stack.pop();
        } 
        else
        {
            current = nullptr;
        }
    }

    bool isDone() override
    {
        return current == nullptr;
    }

    char currentItem() override
    {
        return current->data;
    }

    Iterator* clone(Node* root) override
    {
        return new InorderIterator(root);
    }
};

#endif /* ITERATOR_H */