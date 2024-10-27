#ifndef QUEUE_H
#define QUEUE_H

template<typename T, typename Implementer>
class Queue
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

    void pop() { impl.pop_front(); }

    Reference top() const { return impl.front(); }
};

#endif /* QUEUE_H */