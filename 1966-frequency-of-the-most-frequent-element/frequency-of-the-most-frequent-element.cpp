class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int left = 0;
        long long sum = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            long long target = nums[right];
            long long windowSize = right - left + 1;

            long long cost = target * windowSize - sum;

            while (cost > k) {

                sum -= nums[left];
                left++;

                windowSize = right - left + 1;
                cost = target * windowSize - sum;
            }

            ans = max(ans, (int)windowSize);
        }

        return ans;
    }
};