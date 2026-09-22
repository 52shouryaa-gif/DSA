class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(!root) return {};

        pre.push_back(root->val);

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        pre.insert(pre.end(), left.begin(), left.end());
        pre.insert(pre.end(), right.begin(), right.end());

        return pre;
    }
};