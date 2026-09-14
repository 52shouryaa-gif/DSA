class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int maxi = 0;
        int n = s.size();
        unordered_set<char> mpp;

        while(r<n){
          while (mpp.find(s[r]) != mpp.end()) {
                mpp.erase(s[l]);
                l++;  
            }
       mpp.insert(s[r]);
            maxi = max(r-l+1 , maxi);
            r++;
        }
        return maxi;
    }
};