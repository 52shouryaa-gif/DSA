class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = 0;
        int max_idx = 0;

        for (int k = 0; k < n; k++) {
            if (nums[k] < nums[min_idx]) min_idx = k;
            if (nums[k] > nums[max_idx]) max_idx = k;
        }

        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        int delete_both_front = j + 1;
        int delete_both_back  = n - i;
        int delete_both_ends  = (i + 1) + (n - j);

        return min({delete_both_front, delete_both_back, delete_both_ends});
    }
};