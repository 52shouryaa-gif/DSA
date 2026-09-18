class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> arr(ratings.size() , 0);
        vector<int> rrr(ratings.size() , 0);
        arr[0] = 1;
        rrr[ratings.size()-1] = 1;
        int n = ratings.size();
        int cnt = 0;
        for(int i = 1 ; i < n; i++){
           if(ratings[i]>ratings[i-1]) arr[i] = arr[i-1] + 1;
           else arr[i] = 1;
        }
        for(int i = n-2 ; i>=0; i--){
           if(ratings[i]>ratings[i+1]) rrr[i] = rrr[i+1] + 1;
           else rrr[i] = 1;
        }
        for(int i = 0 ; i < n; i++){
            int t = max(arr[i] , rrr[i]);
            cnt += t;
        }
        return cnt;
    }
};