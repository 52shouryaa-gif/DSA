class Solution {
public:
    // Pass by const reference to avoid copying the string
    int sum(const string& s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int totalSubstrings = 0;

        int mpp[256] = {0}; // Array acts as a lightning-fast map for characters
        int distinct_count = 0; // Tracks the current map size

        while (r < n) {
            // If we are seeing this character for the first time in the window
            if (mpp[s[r]] == 0) {
                distinct_count++;
            }
            mpp[s[r]]++;

            // Shrink window if we exceed 'k' distinct characters
            while (distinct_count > k) {
                mpp[s[l]]--;
                // If the character count drops to 0, it's completely removed from our window
                if (mpp[s[l]] == 0) {
                    distinct_count--;
                }
                l++;
            }
            totalSubstrings += r - l + 1;
            r++;
        }
        return totalSubstrings;
    }
    
    int numberOfSubstrings(string s) {
        return sum(s, 3) - sum(s, 2);
    }
};