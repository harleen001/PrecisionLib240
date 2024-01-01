#include <iostream>
#include "TreeAlgorithms.h"

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    TreeAlgorithms treeAlgo;

    // Example usage of tree algorithms
    std::cout << "Height of the tree: " << treeAlgo.treeHeight(root) << std::endl;
    std::cout << "Size of the tree: " << treeAlgo.treeSize(root) << std::endl;
    std::cout << "Leaf count of the tree: " << treeAlgo.leafCount(root) << std::endl;

    // Perform more operations or test other algorithms

    // Cleanup
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
