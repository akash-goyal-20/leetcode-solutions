class Solution {
public:
    vector<int> travel(TreeNode* root) {
        // Base case
        if (root == NULL) {
            return {0, 0};
        }

        // Get choices from left and right subtrees
        vector<int> left_node_choices = travel(root->left);
        vector<int> right_node_choices = travel(root->right);

        vector<int> options(2);

        // options[0] = maximum money if we ROB this node
        options[0] = root->val 
                   + left_node_choices[1] 
                   + right_node_choices[1];

        // options[1] = maximum money if we SKIP this node
        options[1] = max(left_node_choices[0], left_node_choices[1])
                   + max(right_node_choices[0], right_node_choices[1]);

        return options;
    }

    int rob(TreeNode* root) {
        vector<int> options = travel(root);

        return max(options[0], options[1]);
    }
};