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
    bool isValidBST(TreeNode* root) {
       vector<int>n;
       int cnt = 1;
       solve(root , n);
       for(
        int i = 0 ; i < n.size()-1;i++
       )
       {
        if(n[i]>=n[i+1])return false;
       }
       return true;
    }
        void solve(TreeNode* root ,vector<int>& n){
        if(root == NULL) return ;
        solve(root -> left , n);
        n.push_back(root -> val);
        solve(root -> right , n);

    }
};