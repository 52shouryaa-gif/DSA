class Solution {
public:
    int trap(vector<int>& arr) {
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = arr.size()-1;
        int cnt = 0;
        while(l<r){
           if(arr[l] <= arr[r]){
            if(lmax > arr[l]){
                cnt += lmax-arr[l];
            }
            else lmax = arr[l];
            l++;
           } 
           else{
            if(arr[r]< rmax) cnt += rmax - arr[r];
            else rmax = arr[r];
            r--;
           }
        }
        return cnt;
    }
};