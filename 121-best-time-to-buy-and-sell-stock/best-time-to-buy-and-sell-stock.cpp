class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int maxi = 0;
        int j = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {  j = min(prices[i] , j);

            maxi = prices[i] - j;
            sum = max(sum , maxi);
          
          
        }
        
        return sum;
    }
};