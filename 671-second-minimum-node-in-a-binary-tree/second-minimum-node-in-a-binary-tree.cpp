class Solution {
public:
    long long mini = LLONG_MAX;

    void dfs(TreeNode* root, int rootVal) {
        if (root == NULL) {
            return;
        }

        if (root->val != rootVal) {
            mini = min(mini, (long long)root->val);
        }

        dfs(root->left, rootVal);
        dfs(root->right, rootVal);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int rootVal = root->val;

        dfs(root, rootVal);

        if (mini != LLONG_MAX) {
            return (int)mini;
        }

        return -1;
    }
};