class Solution {
public:
    int sum(const vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int totalSubarrays = 0; 

       
        vector<int> mpp(n + 1, 0); 
        int distinct_count = 0;

        while (r < n) {
           
            if (mpp[nums[r]] == 0) {
                distinct_count++;
            }
            mpp[nums[r]]++;

            while (distinct_count > k) {
                mpp[nums[l]]--;
               
                if (mpp[nums[l]] == 0) {
                    distinct_count--;
                }
                l++;
            }
            
           
            totalSubarrays += r - l + 1;
            r++;
        }
        return totalSubarrays;
    }
  
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return sum(nums, k) - sum(nums, k - 1);
    }
};