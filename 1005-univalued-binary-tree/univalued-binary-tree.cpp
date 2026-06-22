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
    bool dfs(TreeNode* root, int rootVal) {
        if (root == NULL) {
            return true;
        }
        if (root->val != rootVal) {
            return false;
        }

        return dfs(root->left, rootVal) && dfs(root->right, rootVal);
    }
    bool isUnivalTree(TreeNode* root) { return dfs(root, root->val); }
};