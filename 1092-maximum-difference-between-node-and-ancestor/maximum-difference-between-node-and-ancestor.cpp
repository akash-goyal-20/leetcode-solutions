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
    int ans = 0;
    void f(int mini, int maxi, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        ans = max(ans, abs(maxi - mini));

        f(mini, maxi, root->left);
        f(mini, maxi, root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        f(INT_MAX, INT_MIN, root);
        return ans;
    }
};