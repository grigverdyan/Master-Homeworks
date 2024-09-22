#ifndef COMPONENT_DECORATOR_H
#define COMPONENT_DECORATOR_H

// Abstract Stack Component
template <typename T>
class Component
{
public:
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual T top() const = 0;
    virtual void push(T elem) = 0;
    virtual void pop() = 0;

    Component() = default;
    virtual ~Component() = default;

};

#endif /* COMPONENT_DECORATOR_H */