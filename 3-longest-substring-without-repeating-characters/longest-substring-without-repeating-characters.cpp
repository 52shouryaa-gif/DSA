class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int maxi = 0;
        int n = s.size();
       vector<int> mpp(256, -1);
        while(r<n){
          if (mpp[s[r]]!=-1){ 
            if(mpp[s[r]]>=l) {
                l = mpp[s[r]] + 1;             
            }
          }
            mpp[s[r]] = r;
            maxi = max(r-l+1 , maxi);
            r++;
        }
        return maxi;
    }
};