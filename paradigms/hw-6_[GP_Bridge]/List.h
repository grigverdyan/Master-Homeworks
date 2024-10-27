#ifndef LIST_H
#define LIST_H

#include <utility>
#include <cstddef>
#include <stdexcept>

template<typename T>
class List
{
public:
    using value_type    = T;
    using Reference     = T&;
    using Pointer       = T*; 
private:
    struct Node
    {
        value_type  data;
        Node*       prev{nullptr};
        Node*       next{nullptr};
        
        Node(const Reference value) : data(value) {}
    };

    Node*   head{nullptr};
    Node*   tail{nullptr};
    size_t  size{0};

public:
    ~List()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    bool    empty() const { return size == 0; }

    Reference   back() const
    {
        if (empty())
            throw std::runtime_error("List is empty!");
        return tail->data;
    }

    void    pop_back()
    {
        if (empty())
            throw std::runtime_error("List is empty!");
        Node*   tmp = tail;
        if (tail->prev)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            head = tail = nullptr;
        }
        delete tmp;
        --size;
    }

    void    push_back(const Reference elem)
    {
        Node*   node = new Node(elem);
        if (empty())
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        ++size;
    }

    Reference   front() const
    {
        if (empty()) 
            throw std::runtime_error("List is empty!");
        return head->data;
    }

    void pop_front()
    {
        if (empty()) 
            throw std::runtime_error("List is empty!");
        Node* tmp = head;
        if (head->next)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
        {
            head = tail = nullptr;
        }
        delete tmp;
        --size;
    }

    void push_front(const Reference elem)
    {
        Node* node = new Node(elem);
        if (empty())
        {
            head = tail = node;
        }
        else
        {
            head->prev = node;
            node->next = head;
            head = node;
        }
        ++size;
    }
};

#endif /* LIST_H */