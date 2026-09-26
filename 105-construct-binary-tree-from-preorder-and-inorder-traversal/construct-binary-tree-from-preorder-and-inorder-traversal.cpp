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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        int i = 0;
        for (auto it : inorder) {
            mpp[it] = i;
            i++;
        }
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                                   inorder.size() - 1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend,
                        vector<int>& inorder, int instart, int inend,
                        map<int, int>& mpp) {
        if (prestart > preend || instart > inend)
            return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mpp[root->val];
        int numsleft = inroot - instart;
        root->left = buildTree(preorder, prestart + 1, prestart + numsleft,
                               inorder, instart, instart + numsleft - 1, mpp);
        root->right = buildTree(preorder, prestart + numsleft + 1, preend,
                                inorder, instart + numsleft + 1, inend, mpp);
        return root;
    }
};