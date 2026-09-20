class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) {
       
        vector<int> ns = nse(arr);
        vector<int> ps = psee(arr);
        
        int mod = 1e9 + 7;
        long long total = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - ps[i];
            long long right = ns[i] - i;
            
         
            long long count = (left * right) % mod;
            long long contribution = (count * arr[i]) % mod;
            
            total = (total + contribution) % mod;
        }
        
        return total;
    }
private:
    vector<int> nse(vector<int>& arr){
        stack <int> st;
        int n = arr.size();
        vector<int> ns(n, n);
        for(int i = n-1 ; i >=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
           
            ns[i] = st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ns;
    }
    vector<int> psee(vector<int>& arr){
        stack <int> st;
        vector<int> ps(arr.size() , -1);
        for(int i = 0 ; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
           
            ps[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return ps;
    }

};