// Lowest Common Ancestor (LCA) in a Binary Tree
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return (left != nullptr) ? left : right;
    }
};

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int arr[] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    TreeNode* root = insertLevelOrder(arr, root, 0, n);

    Solution solution;

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    
    if (lca != nullptr) {
        cout << "The LCA of nodes " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "No LCA found!" << endl;
    }

    return 0;
}
