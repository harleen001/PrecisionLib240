#include <iostream>
#include "DataStructures.h"

int main() {
    Queue q;
    Stack s;

    // Initializing queue and stack
    initializeQueue(q);
    initializeStack(s);

    // Enqueue elements to the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Push elements to the stack
    push(s, 50);
    push(s, 60);
    push(s, 70);

    // Dequeue elements from the queue and pop elements from the stack
    std::cout << "Dequeue from the queue: " << dequeue(q) << std::endl;
    std::cout << "Dequeue from the queue: " << dequeue(q) << std::endl;
    std::cout << "Pop from the stack: " << pop(s) << std::endl;
    std::cout << "Pop from the stack: " << pop(s) << std::endl;

    return 0;
}
