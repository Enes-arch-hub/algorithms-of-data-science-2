#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Definition for a binary tree node
// ---------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ---------------------------
// Symmetric Tree Solution
// ---------------------------
class Solution {
public:
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;           // both null -> symmetric
        if (!a || !b) return false;          // one null -> not symmetric
        if (a->val != b->val) return false;  // values differ -> not symmetric

        // compare mirrored children
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;              // empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};

// ---------------------------
// Helper function to build sample tree
// ---------------------------
TreeNode* buildExampleTree() {
    // Builds this tree:
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    return root;
}

// ---------------------------
// Main function
// ---------------------------
int main() {
    TreeNode* root = buildExampleTree();

    Solution sol;
    bool result = sol.isSymmetric(root);

    cout << boolalpha << result << endl; // Expected output: true

    return 0;
}