class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0;
        int r = 0;
        int m = s.size();
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        while (l < m && r<g.size()) {
            if (g[r] <= s[l]) {
                r = r + 1;
            }
            l++;
        }
        return r;
    }
};