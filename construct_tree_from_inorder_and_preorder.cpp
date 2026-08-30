#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int index = 0;
    unordered_map<int, int> position;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            position[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int rootValue = preorder[index];
        index++;

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = position[rootValue];

        root->left = build(preorder, start, rootIndex - 1);
        root->right = build(preorder, rootIndex + 1, end);

        return root;
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;

    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "Tree created successfully!" << endl;

    return 0;
}