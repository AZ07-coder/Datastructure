class Solution {
    TreeNode* temp = nullptr;

public:
    void flatten(TreeNode* root) {
        helper(root);
    }

    void helper(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (temp != nullptr) {
            temp->right = root;
        }

        root->left = nullptr;
        temp = root;

        helper(left);
        helper(right);
    }
};