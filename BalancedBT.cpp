#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        if (left == -1 || right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};


int main() {
    Solution obj;

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(6);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(1);

    cout << (obj.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}