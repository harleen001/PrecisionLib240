// QueueOperations.h
#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initializeQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

void enqueue(Queue& q, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (q.front == nullptr) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

int dequeue(Queue& q) {
    if (q.front == nullptr) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1; // Return some error value
    }

    int value = q.front->data;
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    delete temp;
    return value;
}

int getFront(const Queue& q) {
    if (q.front == nullptr) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1; // Return some error value
    }
    return q.front->data;
}

bool isQueueEmpty(const Queue& q) {
    return q.front == nullptr;
}

int getQueueSize(const Queue& q) {
    int count = 0;
    Node* current = q.front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue(Queue& q) {
    while (q.front != nullptr) {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
    }
    q.rear = nullptr;
}

// CircularQueue operations
struct CircularQueue {
    Node* rear;
};

bool isCircularQueueEmpty(const CircularQueue& cq) {
    return cq.rear == nullptr;
}

int getCircularQueueSize(const CircularQueue& cq) {
    if (cq.rear == nullptr) {
        return 0;
    }

    int count = 1;
    Node* temp = cq.rear->next;
    while (temp != cq.rear) {
        count++;
        temp = temp->next;
    }
    return count;
}

void enqueueCircularQueue(CircularQueue& cq, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    if (cq.rear == nullptr) {
        cq.rear = newNode;
        cq.rear->next = cq.rear;
    } else {
        newNode->next = cq.rear->next;
        cq.rear->next = newNode;
        cq.rear = newNode;
    }
}

int dequeueCircularQueue(CircularQueue& cq) {
    if (cq.rear == nullptr) {
        std::cerr << "Circular queue is empty!" << std::endl;
        return -1; // Return some error value
    }

    int value;
    if (cq.rear->next == cq.rear) {
        value = cq.rear->data;
        delete cq.rear;
        cq.rear = nullptr;
    } else {
        Node* temp = cq.rear->next;
        value = temp->data;
        cq.rear->next = temp->next;
        delete temp;
    }
    return value;
}
