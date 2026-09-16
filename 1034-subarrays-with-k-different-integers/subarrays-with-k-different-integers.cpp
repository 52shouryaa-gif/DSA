class Solution {
public:
int sum(vector<int> s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxlen = 0;

        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[s[r]]++;
            while (mpp.size() > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            maxlen += r - l + 1;
            r++;
        }
        return maxlen;
    }
  
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         int a = sum(nums, k);
        int b = sum(nums, k-1);
        return a - b;
    }
};

    