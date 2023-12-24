// Example.cpp
#include <iostream>
#include "TreeStructures.h"

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    std::cout << "Inorder Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Height of the tree: " << getTreeHeight(root) << std::endl;

    return 0;
}
