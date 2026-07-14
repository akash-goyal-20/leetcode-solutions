class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    map<int, int>& inorderIndex) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int rootIndex = inorderIndex[preorder[preStart]];
        int leftSubtreeSize = rootIndex - inStart;

        root->left = build(preorder, preStart + 1, preStart + leftSubtreeSize,
                           inorder, inStart, rootIndex - 1, inorderIndex);

        root->right = build(preorder, preStart + leftSubtreeSize + 1, preEnd,
                            inorder, rootIndex + 1, inEnd, inorderIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int, int> inorderIndex;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inorderIndex);
    }
};