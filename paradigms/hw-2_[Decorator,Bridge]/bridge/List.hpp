#ifndef LIST_BRIDGE_H
#define LIST_BRIDGE_H

#include <memory>
#include <stdexcept>

// Implementer: Abstract List
template <typename T>
class AbstractList
{
public:
    virtual T head() const = 0;
    virtual std::shared_ptr<AbstractList<T>> tail() const = 0;
    virtual std::shared_ptr<AbstractList<T>> cons(T head, std::shared_ptr<AbstractList<T>> tail) const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~AbstractList() = default;
};

// Concrete Implementer: Recursive List
template <typename T>
class RecursiveList : public AbstractList<T>
{
private:
    T _head;
    std::shared_ptr<AbstractList<T>> _tail;
    bool _empty;
    
public:
    RecursiveList(T h, std::shared_ptr<AbstractList<T>> t) 
        : _head(h), _tail(t), _empty(false) 
    {}
    
    RecursiveList() 
        : _empty(true) 
    {}

    T head() const override
    {
        if (_empty) 
            throw std::out_of_range("List is empty!");
        return _head;
    }

    std::shared_ptr<AbstractList<T>> tail() const override 
    {
        if (_empty) 
            throw std::out_of_range("List is empty!");
        return _tail;
    }

    std::shared_ptr<AbstractList<T>> cons(T head, std::shared_ptr<AbstractList<T>> tail) const override 
    {
        return std::make_shared<RecursiveList<T>>(head, tail);
    }

    bool isEmpty() const override 
    {
        return _empty;
    }
};

// Concrete Implementer: Linked List Node
template <typename T>
class LinkedListNode 
{
private:
    T _head;
    std::shared_ptr<LinkedListNode<T>> _tail;

public:
    LinkedListNode(T h, std::shared_ptr<LinkedListNode<T>> t = nullptr)
        : _head(h), _tail(t) 
    {}

    T head() const
    {
        return _head;
    }

    std::shared_ptr<LinkedListNode<T>> tail() const 
    {
        return _tail;
    }
};

// Concrete Implementer: Linked List
template <typename T>
class LinkedList : public AbstractList<T> 
{
private:
    std::shared_ptr<LinkedListNode<T>> _node;

public:
    LinkedList(std::shared_ptr<LinkedListNode<T>> node = nullptr) 
        : _node(node) 
    {}

    T head() const override 
    {
        if (!_node) 
            throw std::out_of_range("List is empty!");
        return _node->head();
    }

    std::shared_ptr<AbstractList<T>> tail() const override 
    {
        if (!_node) 
            throw std::out_of_range("List is empty!");
        return std::make_shared<LinkedList<T>>(_node->tail());
    }

    std::shared_ptr<AbstractList<T>> cons(T head, std::shared_ptr<AbstractList<T>> tail) const override 
    {
        std::shared_ptr<LinkedListNode<T>> newTail = nullptr;

        if (!tail->isEmpty())
            newTail = std::dynamic_pointer_cast<LinkedList<T>>(tail)->_node;

        std::shared_ptr<LinkedListNode<T>> newNode = std::make_shared<LinkedListNode<T>>(head, newTail);
        return std::make_shared<LinkedList<T>>(newNode);
    }

    bool isEmpty() const override
    {
        return !_node;
    }
};

// Abstraction: Stack and Queue
template <typename T>
class AbstractStructure
{
public:
    virtual void push(T elem) = 0;
    virtual T top() const = 0;
    virtual void pop() = 0;
    virtual ~AbstractStructure() = default;
};

// Abstraction: Stack
template <typename T>
class Stack : public AbstractStructure<T>
{
private:
    std::shared_ptr<AbstractList<T>> _impl;

public:
    Stack(std::shared_ptr<AbstractList<T>> impl) 
        : _impl(impl) 
    {}

    void push(T elem) override
    {
        _impl = _impl->cons(elem, _impl);
    }

    T top() const override
    {
        return _impl->head();
    }

    void pop() override
    {
        _impl = _impl->tail();
    }
};


// Abstraction: Queue
// NOTE: Accured some errors in pop()...
template <typename T>
class Queue : public AbstractStructure<T>
{
private:
    std::shared_ptr<AbstractList<T>> _impl;
    std::shared_ptr<AbstractList<T>> _tailImpl;

public:
    Queue(std::shared_ptr<AbstractList<T>> impl) 
        : _impl(std::make_shared<RecursiveList<T>>()), 
          _tailImpl(_impl)
    {}

    void push(T elem) override
    {
        if (_impl->isEmpty())
        {
            _impl = _impl->cons(elem, nullptr);
            _tailImpl = _impl;
        }
        else 
        {
            _tailImpl = _tailImpl->cons(elem, nullptr);
        }
    }

    T top() const override
    {
        if (_impl->isEmpty())
            throw std::out_of_range("Queue is empty!");

        return _impl->head();
    }

    void pop() override
    {
        if (_impl->isEmpty())
            throw std::out_of_range("Queue is empty!");

        _impl = _impl->tail();

        if (_impl->isEmpty())
        {
           _tailImpl = _impl;
        }
    }
};

#endif /* LIST_BRIDGE_H */
