class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxi = 0;
        int n = arr.size();
        stack<int> st;
        int nse = 0;
        int pse = 0;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int ele = st.top();
                nse = i; 
                  st.pop();
                pse = st.empty()?-1:st.top();
              
                maxi = max(maxi , arr[ele]*(nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            int ele = st.top();
            st.pop();
           
            pse = st.empty()?-1:st.top();
            maxi = max(maxi , arr[ele]*(nse - pse - 1));
          
        }
        return maxi;
    }
};