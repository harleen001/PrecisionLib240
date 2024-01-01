// TreeAlgorithms.h
#ifndef TREE_ALGORITHMS_H
#define TREE_ALGORITHMS_H

#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int TreeAlgorithms::treeHeight(const TreeNode* root) {
    if (!root) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

int TreeAlgorithms::treeSize(const TreeNode* root) {
    if (!root) return 0;
    return 1 + treeSize(root->left) + treeSize(root->right);
}

int TreeAlgorithms::leafCount(const TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return leafCount(root->left) + leafCount(root->right);
}

int TreeAlgorithms::levelWidth(const TreeNode* root, int level) {
    if (!root) return 0;
    if (level == 1) return 1;
    return levelWidth(root->left, level - 1) + levelWidth(root->right, level - 1);
}

bool TreeAlgorithms::isFullBinaryTree(const TreeNode* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (root->left && root->right) 
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    return false;
}

bool TreeAlgorithms::isCompleteBinaryTree(const TreeNode* root) {
    if (!root) return true;

    std::queue<const TreeNode*> q;
    q.push(root);
    bool endNodes = false;

    while (!q.empty()) {
        const TreeNode* temp = q.front();
        q.pop();

        if (temp->left) {
            if (endNodes) return false;
            q.push(temp->left);
        } else {
            endNodes = true;
        }

        if (temp->right) {
            if (endNodes) return false;
            q.push(temp->right);
        } else {
            endNodes = true;
        }
    }
    return true;
}

bool isBSTUtil(const TreeNode* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->val) && isBSTUtil(root->right, root->val, maxVal);
}

bool TreeAlgorithms::isBST(const TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

bool areMirror(const TreeNode* root1, const TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->val == root2->val) && areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
}

bool TreeAlgorithms::areMirrorImages(const TreeNode* root1, const TreeNode* root2) {
    return areMirror(root1, root2);
}

TreeNode* TreeAlgorithms::lowestCommonAncestor(const TreeNode* root, int value1, int value2) {
    if (!root) return nullptr;
    if (root->val == value1 || root->val == value2) return const_cast<TreeNode*>(root);

    TreeNode* left = lowestCommonAncestor(root->left, value1, value2);
    TreeNode* right = lowestCommonAncestor(root->right, value1, value2);

    if (left && right) return root;
    return left ? left : right;
}
int TreeAlgorithms::treeHeight(const TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

int TreeAlgorithms::treeSize(const TreeNode* root) {
    if (!root) return 0;
    return 1 + treeSize(root->left) + treeSize(root->right);
}

int TreeAlgorithms::leafCount(const TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return leafCount(root->left) + leafCount(root->right);
}

int TreeAlgorithms::levelWidth(const TreeNode* root, int level) {
    if (!root) return 0;
    if (level == 1) return 1;
    return levelWidth(root->left, level - 1) + levelWidth(root->right, level - 1);
}

bool TreeAlgorithms::isFullBinaryTree(const TreeNode* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (root->left && root->right) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    return false;
}

bool TreeAlgorithms::areStructurallyIdentical(const TreeNode* root1, const TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->val == root2->val) &&
           areStructurallyIdentical(root1->left, root2->left) &&
           areStructurallyIdentical(root1->right, root2->right);
}

#endif // TREE_ALGORITHMS_H
