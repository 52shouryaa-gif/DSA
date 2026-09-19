class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int originalSize = nums.size();

        nums.insert(nums.end(), nums.begin(), nums.end());

        int n = nums.size();

        stack<int> st;
        vector<int> ng(n, -1);

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[i] >= st.top())
                st.pop();

            if(st.empty())
                ng[i] = -1;
            else
                ng[i] = st.top();

            st.push(nums[i]);
        }

        ng.resize(originalSize);

        return ng;
    }
};