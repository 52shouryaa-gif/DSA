class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int m = t.size();
        int sin = 0;
        int minlen = INT_MAX;
        int cnt = 0;
        int mpp[256] = {0};
        for (int i = 0; i < m; i++) {
            mpp[t[i]]++;
        }
        while (r < n) {
            if (mpp[s[r]] > 0) {
                cnt++;
            }
            mpp[s[r]]--;
            while (cnt == m) {
                if (minlen > r - l + 1) {
                    minlen = r - l + 1;
                    sin = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){ cnt--;}
                l++;
            }
            r++;
        }
        return (minlen==INT_MAX)?"":s.substr(sin, minlen);
    }
};