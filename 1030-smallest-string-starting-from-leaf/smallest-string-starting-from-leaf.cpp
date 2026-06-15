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
    vector<string> ans;
    void dfs(TreeNode* root, string path) {
        if (root == NULL) {
            return;
        }
        path = path + char(root->val + 'a');
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);

        for (int i = 0; i < ans.size(); i++) {
            reverse(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());

        return ans[0];
    }
};