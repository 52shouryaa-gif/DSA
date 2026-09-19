class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int l = 0;
        long long cost = 0;
        int maxi = 0;
        int r = 0;
        long long sum = 0;
        int n = nums.size();

        while (r < n) {

            sum += nums[r];

            cost = 1LL * (r - l + 1) * nums[r] - sum;

            while (cost > k) {
                sum -= nums[l];
                l++;

                cost = 1LL * (r - l + 1) * nums[r] - sum;
            }

            maxi = max(r - l + 1, maxi);

            r++;
        }

        return maxi;
    }
};