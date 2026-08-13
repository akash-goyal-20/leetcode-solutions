/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (root == NULL) {
            return 0;
        }
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        int take = root->val;
        if (root->left) {
            take = take + f(root->left->left, dp) + f(root->left->right, dp);
        }
        if (root->right) {
            take = take + f(root->right->left, dp) + f(root->right->right, dp);
        }
        int skip = f(root->left, dp) + f(root->right, dp);

        return dp[root] = max(take, skip);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return f(root, dp);
    }
};