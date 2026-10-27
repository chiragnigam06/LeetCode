class Solution {
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        int left = checkHeight(root->left);
        if (left == -1) return -1;
        int right = checkHeight(root->right);
        if (right == -1) return -1;

        if (std::abs(left - right) > 1) return -1;
        return 1 + std::max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};