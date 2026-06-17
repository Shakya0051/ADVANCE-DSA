#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(18);
    root->right = new TreeNode(40);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(14);

    Solution sol;
    cout << sol.maxDepth(root);

    return 0;
}