class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> ng(n, -1);

        for(int i = 2*n - 1; i >= 0; i--) {
            int x = nums[i%n];

            while(!st.empty() && x >= st.top())
                st.pop();

            if(st.empty())
                ng[i%n] = -1;
            else
                ng[i%n] = st.top();

            st.push(nums[i%n]);
        }

      

        return ng;
    }
};