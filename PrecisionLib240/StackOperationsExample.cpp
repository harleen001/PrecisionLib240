// Example.cpp
#include <iostream>
#include "StackOperations.h"

int main() {
    Stack s;
    s.top = nullptr; // Initialize the stack

    push(s, 10);
    push(s, 20);
    push(s, 30);

    std::cout << "Size of the stack: " << getStackSize(s) << std::endl;

    std::cout << "Popped value: " << pop(s) << std::endl;

    std::cout << "Is stack empty? " << (isStackEmpty(s) ? "Yes" : "No") << std::endl;

    std::cout << "Peek value: " << peek(s) << std::endl;

    clearStack(s);

    std::cout << "Is stack empty after clearing? " << (isStackEmpty(s) ? "Yes" : "No") << std::endl;

    return 0;
}
