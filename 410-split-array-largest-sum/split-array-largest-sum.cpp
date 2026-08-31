#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:
    // Returns pair: {can_split_into_k_or_fewer_subarrays, max_subarray_sum_formed}
    pair<bool, int> mini(const vector<int>& nums, int mid, int k) {
        int count = 1;
        int current_sum = 0;
        int max_sum = 0;

        for (int x : nums) {
            if (current_sum + x > mid) {
                // Start a new subarray
                count++;
                current_sum = x;
            } else {
                current_sum += x;
            }
            max_sum = max(max_sum, current_sum);
        }

        bool is_valid = (count <= k);
        return {is_valid, max_sum};
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
           
            auto [possible, maxi] = mini(nums, mid, k);

            if (possible) {
                ans = maxi;       
                right = mid - 1;   
            } else {
                left = mid + 1;    
            }
        }
        return ans;
    }
};