class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int cnt = INT_MAX;
        int op = -1;
        int n = nums.size()-1;
        if(nums.size()==2){
            if(nums[0]-nums[1]<=k) return 0;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            int maxi = *max_element(nums.begin() , nums.begin() + i);
            int mini = *min_element(nums.begin()+i , nums.end());
            
            if(maxi - mini <= k) {
            return i;   
        }
        }
        return op;
    }
};