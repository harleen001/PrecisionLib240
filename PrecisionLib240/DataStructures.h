#include <iostream>

// Queue implementation using arrays
const int MAX_SIZE = 100;

struct Queue {
    int elements[MAX_SIZE];
    int front, rear;
};

void initializeQueue(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isQueueEmpty(const Queue& q) {
    return q.front == -1 && q.rear == -1;
}

bool isQueueFull(const Queue& q) {
    return (q.rear + 1) % MAX_SIZE == q.front;
}

void enqueue(Queue& q, int value) {
    if (isQueueFull(q)) {
        std::cout << "Queue is full. Cannot enqueue.\n";
        return;
    } else if (isQueueEmpty(q)) {
        q.front = 0;
        q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % MAX_SIZE;
    }
    q.elements[q.rear] = value;
}

int dequeue(Queue& q) {
    if (isQueueEmpty(q)) {
        std::cout << "Queue is empty. Cannot dequeue.\n";
        return -1; // Assuming -1 indicates an error or empty value
    } else if (q.front == q.rear) {
        int value = q.elements[q.front];
        initializeQueue(q);
        return value;
    } else {
        int value = q.elements[q.front];
        q.front = (q.front + 1) % MAX_SIZE;
        return value;
    }
}

int getQueueSize(const Queue& q) {
    if (isQueueEmpty(q)) {
        return 0;
    } else {
        return (MAX_SIZE - q.front + q.rear + 1) % MAX_SIZE;
    }
}

void clearQueue(Queue& q) {
    initializeQueue(q);
}

// Stack implementation using arrays
const int STACK_MAX_SIZE = 100;

struct Stack {
    int elements[STACK_MAX_SIZE];
    int top;
};

void initializeStack(Stack& s) {
    s.top = -1;
}

bool isStackEmpty(const Stack& s) {
    return s.top == -1;
}

bool isStackFull(const Stack& s) {
    return s.top == STACK_MAX_SIZE - 1;
}

void push(Stack& s, int value) {
    if (isStackFull(s)) {
        std::cout << "Stack is full. Cannot push.\n";
        return;
    }
    s.elements[++s.top] = value;
}

int pop(Stack& s) {
    if (isStackEmpty(s)) {
        std::cout << "Stack is empty. Cannot pop.\n";
        return -1; // Assuming -1 indicates an error or empty value
    }
    return s.elements[s.top--];
}
