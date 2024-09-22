#ifndef DYNAMIC_STACK_DECORATOR_H
#define DYNAMIC_STACK_DECORATOR_H

#include <vector>
#include <memory>

#include "Stack.hpp"

// Decorator pattern: DynamicStack impl
template <typename T>
class DynamicStack : public Component<T>
{
private:
    std::unique_ptr<Component<T>> _stack;

public:
    DynamicStack(std::unique_ptr<Component<T>> stack) 
        : _stack(std::move(stack)) 
    {}

    DynamicStack(const DynamicStack&) = delete;
    DynamicStack(DynamicStack&&) = delete;
    T& operator= (const DynamicStack&) = delete;
    T& operator= (DynamicStack&&) = delete;

    size_t size() const override
    {
        return _stack->size();
    }

    bool empty() const override
    {
        return _stack->empty();
    }

    T top() const override
    {
        return _stack->top();
    }

    void push(T elem) override
    {
        if (_stack->size() == _capacity())
            extendStack();

        _stack->push(elem);
    }

    void pop() override
    {
        _stack->pop();
        if ( _capacity() > 1 && _stack->size() <= _capacity() / 4)
            reduceStack();
    }

private:
    size_t _capacity() const 
    {
        return dynamic_cast<Stack<T>*>(_stack.get())->_capacity;
    }

    void extendStack()
    {
        auto new_capacity = _capacity() * 2;
        std::unique_ptr<Component<T>> new_stack = std::make_unique<Stack<T>>(new_capacity);
        while (!empty())
        {
            new_stack->push(_stack->top());
            _stack->pop();
        }
        _stack = std::move(new_stack);
    }

    void reduceStack()
    {
        auto new_capacity = _capacity() / 2;
        std::unique_ptr<Component<T>> new_stack = std::make_unique<Stack<T>>(new_capacity);
        while (!empty())
        {
            new_stack->push(_stack->top());
            _stack->pop();
        }
        _stack = std::move(new_stack);
    }
};

#endif /* DYNAMIC_STACK_DECORATOR_H*/