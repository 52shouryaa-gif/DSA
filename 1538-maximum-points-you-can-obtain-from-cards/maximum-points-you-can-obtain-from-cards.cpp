class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int lsum = 0;
        int maxi = 0;
        for(int i = 0 ; i < k ; i++){
            lsum += c[i];
            maxi = max(maxi , lsum);
        }
        int rsum = c.size()-1;
        for(int i =  k-1; i >=0 ; i--){
            lsum = lsum-c[i] + c[rsum];
            maxi = max(maxi , lsum);
            rsum = rsum -1;

        }
        return maxi;
    }
};