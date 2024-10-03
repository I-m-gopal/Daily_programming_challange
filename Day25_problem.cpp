//: Check if a Binary Tree is a Binary Search Tree (BST)
#include <iostream>
#include <limits.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (node == NULL) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
    }
};

TreeNode* newNode(int data) {
    return new TreeNode(data);
}

int main() {
    Solution sol;

    TreeNode* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    
    cout << (sol.isValidBST(root) ? "True" : "False") << endl;  // Output: True

    return 0;
}
