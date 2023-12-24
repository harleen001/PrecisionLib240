// Example.cpp
#include <iostream>
#include "QueueOperations.h"

int main() {
    Queue q;
    CircularQueue cq;
    initializeQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    std::cout << "Front element of the queue: " << getFront(q) << std::endl;

    std::cout << "Dequeued element: " << dequeue(q) << std::endl;

    std::cout << "Is queue empty? " << (isQueueEmpty(q) ? "Yes" : "No") << std::endl;

    std::cout << "Size of the queue: " << getQueueSize(q) << std::endl;

    clearQueue(q);

    std::cout << "Is queue empty after clearing? " << (isQueueEmpty(q) ? "Yes" : "No") << std::endl;

    return 0;
}
