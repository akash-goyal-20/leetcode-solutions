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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<long long, TreeNode*>> q;
        q.push({1, root});
        long long maxDia = 0;
        

        while (!q.empty()) {
            int size = q.size();
            long long left = 0;
        long long right = 0;
            long long start = q.front().first;

            for (int i = 0; i < size; i++) {
                long long index = q.front().first - start;
                auto node = q.front().second;
                q.pop();

                if (i == 0) {
                    left = index;
                }
                if (i == size - 1) {
                    right = index;
                }

                if (node->left != NULL) {
                    q.push({index * 2, node->left});
                }
                if (node->right != NULL) {
                    q.push({index * 2 + 1, node->right});
                }
            }
            maxDia = max(maxDia, right - left + 1);
        }

        return (int)maxDia;
    }
};