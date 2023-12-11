#include <iostream>
#include "LinkedList.h"

int main() {
    Node* head = nullptr;

    // Test the functions
    insertNodeAtBeginning(head, 10);
    insertNodeAtEnd(head, 20);
    insertNodeAtBeginning(head, 5);
    insertNodeAtEnd(head, 30);

    std::cout << "Original list: ";
    printList(head);

    std::cout << "Node count: " << getNodeCount(head) << std::endl;

    std::cout << "Is 20 in the list? " << (searchNode(head, 20) ? "Yes" : "No") << std::endl;

    deleteNode(head, 20);
    std::cout << "List after deleting 20: ";
    printList(head);

    reverseList(head);
    std::cout << "Reversed list: ";
    printList(head);

    Node* newList = createNode(15);
    insertNodeAtEnd(newList, 25);
    insertNodeAtEnd(newList, 35);
    std::cout << "New list: ";
    printList(newList);

    std::cout << "Merged list: ";
    Node* mergedList = mergeLists(head, newList);
    printList(mergedList);

    deleteList(head);
    deleteList(newList);

    return 0;
}
