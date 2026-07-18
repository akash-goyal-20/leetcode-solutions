/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<long long,int> mp;
    int cnt = 0;

    void dfs(TreeNode* root, long long pathSum,int targetSum){
        if(root == NULL){
            return;
        }
        pathSum = pathSum + root->val;
        if(mp.find(pathSum - targetSum)!=mp.end()){
            cnt = cnt + mp[pathSum - targetSum];
        }
        mp[pathSum]++;
        dfs(root->left,pathSum,targetSum);
        dfs(root->right,pathSum,targetSum);

        mp[pathSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]++;
        dfs(root,0,targetSum);
        return cnt;
    }
};