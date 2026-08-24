class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) {
            sum += stone;
        }
        
        int ans = sum;
        for (int i = stones.size() - 2; i >= 1; --i) {
            sum -= stones[i + 1];
            ans = max(sum - ans, ans);
        }
        
        return ans;
    }
};