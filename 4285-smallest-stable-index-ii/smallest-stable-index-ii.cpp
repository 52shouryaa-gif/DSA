class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Array to store min(nums[i..n-1])
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        
        // Precompute the suffix minimums from right to left
        for(int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        
        int currentMax = nums[0]; // To track max(nums[0..i])
        
        // Iterate left to right to find the first stable index
        for(int i = 0; i < n; i++) {
            currentMax = max(currentMax, nums[i]);
            
            // Check if the instability score <= k
            if(currentMax - suffMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};