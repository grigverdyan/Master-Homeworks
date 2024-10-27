#ifndef STACK_DECORATOR_H
#define STACK_DECORATOR_H

#include <vector>
#include <memory>

#include "Component.hpp"

// Stack impl
template <typename T>
class Stack : public Component<T>
{
public:
    size_t _capacity;
    T _top;
    std::vector<T> _data;
public:
    Stack(size_t capacity = 10) 
        : _capacity(capacity)
        , _top(-1) 
    {
        _data.resize(capacity);
    }

    ~Stack()
    {
        while(!empty()) 
        {
            pop();
        }
    }

    Stack(const Stack&) = delete;
    Stack(Stack &&) = delete;
    T& operator= (const Stack&) = delete;
    T& operator= (Stack &&) = delete;

    size_t size() const override 
    {
        return (_top + 1);
    }

    bool empty() const override
    {
        return (_top == -1);
    }

    T top() const override
    {
        if (empty())
            throw std::out_of_range("Stack is empty!");
        
        return (_data[_top]);
    }

    void push(T elem) override
    {
        if (_top + 1 == _capacity)
            throw std::overflow_error("Stack overflow!");
        
        _data[++_top] = elem;
    }

    void pop() override
    {
        if (empty())
            throw std::out_of_range("Stack underflow!");

        _top--;
    }
};

#endif /* STACK_DECORATOR_H */