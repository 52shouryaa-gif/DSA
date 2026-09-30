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
    bool findTarget(TreeNode* root, int k) {
       
         vector<int> ar;
          ite(root , ar);
           int i = 0;
        int j = ar.size()-1;
        while(i<j){
           if(ar[i] + ar[j] == k) return true;
           else if (ar[i] + ar[j]> k) j--;
           else i++;
        }
        return false;
    }
    void ite(TreeNode* root ,  vector<int>& ar){
        if(!root) return ;

        ite( root -> left , ar);
        ar.push_back(root -> val);
        ite(root -> right , ar);
    }
};