#ifndef NODE_H
#define NODE_H

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char val) 
        :data(val)
        , left(nullptr)
        , right(nullptr) 
    {}
};

#endif /* NODE_H */