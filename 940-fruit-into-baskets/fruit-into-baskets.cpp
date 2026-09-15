class Solution {
public:
    int totalFruit(vector<int>& z) {
        int l = 0;
        int r = 0;
        int k = 2;
        int maxi = 0;
        int n = z.size();
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[z[r]]++;
            if (mpp.size() > k) {
                mpp[z[l]]--;
                if (mpp[z[l]] == 0)
                    mpp.erase(z[l]);
                l++;
            }
            if (mpp.size() <= k) {
                maxi = r - l + 1;
            }
            r++;
        }
        return maxi;
    }
};