// StackOperations.h
#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void push(Stack& s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

int pop(Stack& s) {
    if (s.top == nullptr) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1; // Return some error value
    }

    int value = s.top->data;
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    return value;
}

int peek(const Stack& s) {
    if (s.top == nullptr) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1; // Return some error value
    }
    return s.top->data;
}

bool isStackEmpty(const Stack& s) {
    return s.top == nullptr;
}

int getStackSize(const Stack& s) {
    int count = 0;
    Node* current = s.top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearStack(Stack& s) {
    while (s.top != nullptr) {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

bool isPalindrome(const char* str);
int evaluatePostfixExpression(const char* expression);
void convertInfixToPostfix(const char* infix, char* postfix);
bool isBalancedParentheses(const char* expression);
