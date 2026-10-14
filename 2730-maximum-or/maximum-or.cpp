class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
     vector<long long > prefix(n+1 , 0);
     vector<long long> suffix(n+1 , 0);
     long long  res = 0;
     long long p = 1<<k;
     for(int i = 0 ; i < n ; i++){
        prefix[i+1] = prefix[i] | nums[i];
     }
      for(int i = n-1 ; i >=0 ; i--){
        suffix[i] = suffix[i+1] | nums[i];
     }
     for(int i = 0 ; i < n ; i++){
        res = max(res , prefix[i]|(nums[i]*p) | suffix[i+1]);
     }
     return res;
    }
};