class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(')
                st.push(i);

            else if(s[i] == ')') {

                reverse(s.begin() + st.top() + 1,
                        s.begin() + i);

                st.pop();
            }
        }

        string t;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '(' && s[i] != ')')
                t += s[i];
        }

        return t;
    }
};