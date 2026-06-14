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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) {
            return false;
        }
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, NULL});
        int step = 0;
        int d1 = -1;
        int d2 = -1;

        TreeNode* p1;
        TreeNode* p2;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();
                if (node->val == x) {
                    d1 = step;
                    p1 = parent;
                }
                if (node->val == y) {
                    d2 = step;
                    p2 = parent;
                }

                if (node->left != NULL) {
                    q.push({node->left, node});
                }
                if (node->right != NULL) {
                    q.push({node->right, node});
                }
            }
            step++;
        }

        if (d1 == d2 && p1 != p2) {
            return true;
        }
        return false;
    }
};