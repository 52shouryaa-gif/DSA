class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n , 0);
            int xo = 0;
        for(int i =0; i<n;i++){
             arr[i] = start + i*2;
        }
        for(int i =0; i<n;i++){
             xo = xo^arr[i];
        }
        return xo;
    }
};