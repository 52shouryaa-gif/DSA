#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

private:
    vector<int> nge(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ng(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ng[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ng;
    }

    vector<int> pgee(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pg(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pg;
    }

    vector<int> nse(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ns(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ns;
    }

    vector<int> psee(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ps(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ps;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> ns = nse(arr);
        vector<int> ps = psee(arr);
        long long total = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - ps[i];
            long long right = ns[i] - i;
            
            long long count = left * right;
            long long contribution = count * arr[i];
            
            total += contribution;
        }
        
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> ng = nge(arr);
        vector<int> pg = pgee(arr);
        long long total = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pg[i];
            long long right = ng[i] - i;
            
            long long count = left * right;
            long long contribution = count * arr[i];
            
            total += contribution;
        }
        
        return total;
    }
};