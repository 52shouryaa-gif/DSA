class Solution {
public:
int sum(vector<int>& nums , int  k){
        int l = 0;
        int r = 0;
        int cnt = 0;
        int maxlen = 0;
        int n = nums.size();
        if(k<0) return 0;
        while (r < n) {
            if (nums[r] % 2 == 1)
                cnt++;
            while (cnt > k) {
                if (nums[l] % 2 == 1) cnt--;
                l++;
            }
            maxlen += r-l+1;
            r++;
        }
        return maxlen;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       int a = sum(nums , k);
       int b = sum(nums , k-1);
       return a-b;
    }
};