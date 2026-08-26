#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int current_sum = 0;
       
        unordered_map<int, int> prefix_map;
        prefix_map[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            
            // If (current_sum - k) exists in the map, it means we found a subarray
            if (prefix_map.find(current_sum - k) != prefix_map.end()) {
                count += prefix_map[current_sum - k];
            }
            
            // Add the current prefix sum to the map for future iterations
            prefix_map[current_sum]++;
        }
        
        return count;
    }
};