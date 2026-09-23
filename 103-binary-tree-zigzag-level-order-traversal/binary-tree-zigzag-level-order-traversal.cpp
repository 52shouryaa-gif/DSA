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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> z;
         if (!root) return z;
         queue<TreeNode*> q;
         q.push(root);
         bool t = true;
         while(!q.empty()){
            int n = q.size();
            vector<int> ans(n);
            for(int i = 0 ; i < n ; i++){
                int ind = t?i:n-i-1;
                TreeNode* node = q.front();
                q.pop();
                ans[ind] = node->val;
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }
            t = !t;
            z.push_back(ans);
         }
         return z;
    }
};