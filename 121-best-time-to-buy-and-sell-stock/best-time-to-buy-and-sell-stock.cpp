class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int maxi = 0;
        int j = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[j] >= prices[i]) {
                j = i;
            } else {
                sum = prices[i] - prices[j];
                maxi = max(sum, maxi);
            }
        }
        
        return maxi;
    }
};