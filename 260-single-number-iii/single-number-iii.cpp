class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(long long i = 0 ; i < nums.size() ; i++){
          x = x^nums[i];
        }
        long long rightm = x&(-x);
        int b = 0; 
        int c = 0;
        for(long long i = 0 ; i < nums.size() ; i++){
            if(nums[i]&rightm) b = b ^ nums[i];
            else c =  c^nums[i];
        }
        return {b , c};
    }
};