class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> a;
        string b;
        int mini = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                a.push_back(i);
        }

        if (a.size() < k)
            return "";

        k--;
        for (int i = 0; i < a.size() - k; i++) {
            int len;
            len = a[i + k] - a[i] + 1;
            string temp = s.substr(a[i], len);
            if (b == "" || len < mini) {
                mini = len;
                b = temp;
            } else if (len == mini) {
                if (b > temp) {
                    b = temp;
                }
            }
        }
        return b;
    }
};