class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int x = n;
        while(n>0){
         sum+=n%10;
         prod = prod*(n%10);
         n = n/10;
        }
        if(x%(sum+prod)==0) return true;
        else return false;
    }
};