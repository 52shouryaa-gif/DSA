class Solution {
public:
    int sum(string s , int k){
        int l = 0; 
        int r = 0 ; 
        int n = s.size();
        int maxlen = 0;

        unordered_map<char , int> mpp;
        while(r<n){
        mpp[s[r]]++;
        while(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        maxlen += r-l+1;
        r++;
        }
        return maxlen;
    }
    int numberOfSubstrings(string s) {
        int a = sum( s , 3);
        int b = sum( s , 2);
        return a-b;
    }
};