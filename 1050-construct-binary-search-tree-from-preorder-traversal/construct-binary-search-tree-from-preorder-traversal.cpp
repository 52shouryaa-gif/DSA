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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder , i  , INT_MAX);
    }
    TreeNode* build(vector<int>& p , int& i , int val){
        if( i == p.size() || p[i]>val) return NULL;
        TreeNode* root = new TreeNode(p[i++]);
        root -> left = build(p, i , root->val);
       root -> right =  build(p , i , val );
       return root;
    }
};