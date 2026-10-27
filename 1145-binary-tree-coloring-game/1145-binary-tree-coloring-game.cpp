/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int leftSize = 0;
    int rightSize = 0;

    int countNodes(TreeNode* node, int x) {
        if (!node) return 0;

        int l = countNodes(node->left, x);
        int r = countNodes(node->right, x);

        if (node->val == x) {
            leftSize = l;
            rightSize = r;
        }

        return 1 + l + r;
    }

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        countNodes(root, x);
        int parentSize = n - (leftSize + rightSize + 1);

        int maxRegion = std::max({leftSize, rightSize, parentSize});
        return maxRegion > n / 2;
    }
};