class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26 , 0);
        int r = 0 ; 
        int l = 0;
        int n = s.size();
        int maxlen = 0;
        int freq = 0;
        while(r<n){
            mpp[s[r] - 'A']++;
            freq = max(freq , mpp[s[r] - 'A']);
           int changes = r-l+1 - freq;
            if(changes > k){
                mpp[s[l] - 'A']--;
                l++;
            }
            else {
                maxlen = max(maxlen , r-l+1);

            }
            r++;

        }
        return maxlen;
    }
};