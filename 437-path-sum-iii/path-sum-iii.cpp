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
    int total = 0;
    void f(TreeNode* root, int targetSum, long long currentSum) {
        if (root == NULL) {
            return;
        }
        currentSum = currentSum + root->val;
        if (currentSum == targetSum) {
            total++;
        }
        f(root->left, targetSum, currentSum);
        f(root->right, targetSum, currentSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        f(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return total;
    }
};