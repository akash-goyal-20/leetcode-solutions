class Solution {
public:
    int total = 0;
    unordered_map<long long, int> mp;

    void f(TreeNode* root, int targetSum, long long currentSum) {
        if (root == NULL)
            return;

        currentSum += root->val;

        total += mp[currentSum - targetSum];

        mp[currentSum]++;

        f(root->left, targetSum, currentSum);
        f(root->right, targetSum, currentSum);

        mp[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;

        f(root, targetSum, 0);

        return total;
    }
};