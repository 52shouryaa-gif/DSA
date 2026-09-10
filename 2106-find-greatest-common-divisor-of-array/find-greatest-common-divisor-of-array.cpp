class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int t = gcd(nums[0] , nums.back());
        return t;
    }
};