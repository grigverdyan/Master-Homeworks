#ifndef STACK_H
#define STACK_H

template<typename T, typename Implementer>
class Stack
{
public:
    using value_type    = T;
    using Reference     = T&;
    using Pointer       = T*; 
private:
    Implementer impl;

public:
    bool empty() const { return impl.empty(); }

    void push(value_type elem) { impl.push_back(elem); }

    void pop() { impl.pop_back(); }

    Reference top() const { return impl.back(); }
};

#endif /* STACK_H */