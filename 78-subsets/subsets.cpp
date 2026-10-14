class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1<<nums.size();
         vector<vector<int>>t;
        for(int i = 0 ; i < n; i++){
           vector<int>ans;
           for(int j = 0 ; j < nums.size() ; j++){
            if(i & (1<<j)) ans.push_back(nums[j]);
           }
           t.push_back(ans);
        }
        return t;
    }
};