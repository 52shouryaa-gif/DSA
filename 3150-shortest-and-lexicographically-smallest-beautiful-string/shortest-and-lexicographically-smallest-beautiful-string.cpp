class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int count1 = 0;
        int mini = INT_MAX;
        string b = "";

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') {
                count1++;
            }

            while (count1 == k) {
                int len = right - left + 1;
                string temp = s.substr(left, len);

                if (b == "" || len < mini) {
                    mini = len;
                    b = temp;
                } else if (len == mini) {
                    if (temp < b) {
                        b = temp;
                    }
                }

                if (s[left] == '1') {
                    count1--;
                }
                left++;
            }
        }

        return b;
    }
};