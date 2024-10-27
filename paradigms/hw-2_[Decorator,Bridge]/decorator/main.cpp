#include <iostream>
#include "Stack.hpp"
#include "DynamicStack.hpp"
// #include "List.hpp"

int main()
{
    std::unique_ptr<Component<int>> stack = std::make_unique<Stack<int>>(4);

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);

    while (!stack->empty())
    {
        std::cout << stack->top()<<std::endl;
        stack->pop();
    }

    DynamicStack<int> dynamicStack(std::move(stack));

    dynamicStack.push(1);
    dynamicStack.push(2);
    dynamicStack.push(3);
    dynamicStack.push(4);

    while (!dynamicStack.empty())
    {
        std::cout << dynamicStack.top()<<std::endl;
        dynamicStack.pop();
    }

    return 0;
}