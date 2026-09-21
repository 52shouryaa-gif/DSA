class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string st = "";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && num[i] < st.back()) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        
        int kt = 0;
        while (kt < st.size() && st[kt] == '0') {
            kt++;
        }
        st = st.substr(kt);

        return st.empty() ? "0" : st; 
    }
};