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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
    }

private:
    TreeNode* buildTree(const vector<int>& inorder, int ins, int ine, 
                       const vector<int>& postorder, int pos, int poe, 
                       unordered_map<int, int>& mpp) {
        if (ins > ine || pos > poe) return nullptr;

        TreeNode* root = new TreeNode(postorder[poe]);
        int inroot = mpp[postorder[poe]];
        int numsleft = inroot - ins;

        root->left = buildTree(inorder, ins, inroot - 1, postorder, pos, pos + numsleft - 1, mpp);
       
        root->right = buildTree(inorder, inroot + 1, ine, postorder, pos + numsleft, poe - 1, mpp);

        return root;
    }
};