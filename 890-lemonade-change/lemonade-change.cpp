class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt = 0;
        int cntt = 0;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i]==5) cnt++;
           else if(bills[i]==10) {
                cntt++;
                cnt--;
                if(cnt==-1) break;
            }
            else {
                if(cntt==0){
                    cnt--;
                    cnt--;
                    cnt--;
                    if(cnt<=-1) break;
                }
               else{ 
                cnt--;
                cntt--;
                if(cnt<=-1|| cntt<=-1) break;
            }
            }
        }
        if(cnt<0||cntt<0) return false;
        else return true;
    }
};