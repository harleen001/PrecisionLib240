// TreeStructures.h
#pragma once
#include <iostream>
#include <queue>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* createTreeNode(int value) {
    return new TreeNode(value);
}

void insertNode(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = createTreeNode(value);
        return;
    }

    if (value < root->value) {
        insertNode(root->left, value);
    } else if (value > root->value) {
        insertNode(root->right, value);
    }
}

bool searchNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->value == value) {
        return true;
    } else if (value < root->value) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

void deleteNode(TreeNode*& root, int value) {
    // Implementation for deleting a node from the tree
    // Not included in this basic example
}

int getTreeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->value << " ";
    inOrderTraversal(root->right);
}

// Implementations for preOrderTraversal, postOrderTraversal, and levelOrderTraversal can be added similarly
