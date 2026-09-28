class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int cnt = 0;
        for(char n:s){
            if(n == '('){
                cnt++;
                maxi = max(cnt , maxi);
            }
            if(n == ')') cnt--;
        }
        return maxi;
    }
};