#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int current_sum = 0;
       
        map<int, int> prefix_map;
        prefix_map[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            int remove = current_sum-k;
            count+=prefix_map[remove];
            prefix_map[current_sum]++;
        }
        
        return count;
    }
};