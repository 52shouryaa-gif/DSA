class Solution {
public:
    int candy(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        int sum = 1;
        while(i<n){
            if(nums[i] == nums[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && nums[i]>nums[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 0;
            while(i<n && nums[i]<nums[i-1]){
                down++;
                sum += down;
                i++;
            }
          
            if(peak<=down){
                // 5 1 2 3 4 
                // 5 4 3 2 1 
                sum += down - peak+1;
            }
        }
        return sum;

    }
};