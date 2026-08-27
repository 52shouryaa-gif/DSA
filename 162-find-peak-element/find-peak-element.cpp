class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int right = nums.size()-1;
        int left = 0;
        int mid;
        if(nums.size() == 1) return 0;
        if(nums[right]>nums[right - 1]) return right;
        if(nums[left]> nums[left+1]) return left;
       
        while(left<=right){
             mid = (left + right)/2;
            if(nums[mid]>nums[mid + 1] && nums[mid]>nums[mid - 1]) return mid;
            if(nums[mid]<nums[mid + 1]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return mid ;
    }
};