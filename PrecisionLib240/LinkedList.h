#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function declarations
Node* createNode(int data);
void insertNodeAtBeginning(Node*& head, int data);
void insertNodeAtEnd(Node*& head, int data);
void deleteNode(Node*& head, int data);
bool searchNode(const Node* head, int data);
int getNodeCount(const Node* head);
void reverseList(Node*& head);
void deleteList(Node*& head);
void printList(const Node* head);
Node* mergeLists(Node* list1, Node* list2);

// Function implementations
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNodeAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertNodeAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node*& head, int data) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == data) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

bool searchNode(const Node* head, int data) {
    const Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int getNodeCount(const Node* head) {
    int count = 0;
    const Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverseList(Node*& head) {
    Node *prev = nullptr, *current = head, *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void printList(const Node* head) {
    const Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    if (list1->data < list2->data) {
        list1->next = mergeLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeLists(list1, list2->next);
        return list2;
    }
}

#endif // LINKEDLIST_H
