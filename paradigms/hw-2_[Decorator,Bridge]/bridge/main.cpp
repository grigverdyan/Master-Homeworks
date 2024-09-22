#include <iostream>
#include "List.hpp"

int main()
{
    // Stack example using Recursive List
    std::shared_ptr<AbstractList<int>> recursiveList = std::make_shared<RecursiveList<int>>();
    Stack<int> recursiveStack(recursiveList);

    recursiveStack.push(10);
    recursiveStack.push(20);
    recursiveStack.push(30);

    std::cout << "Stack (Recursive List) Top: " << recursiveStack.top() << std::endl;
    recursiveStack.pop();
    std::cout << "Stack (Recursive List) Top after pop: " << recursiveStack.top() << std::endl;
    
    return 0;
}