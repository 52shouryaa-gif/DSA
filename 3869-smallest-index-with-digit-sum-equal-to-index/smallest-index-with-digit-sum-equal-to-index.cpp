class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            int x =  nums[i];
               while(x>0){
                    cnt += x%10;
                    x = x/10;
                }
                nums[i] = cnt;
                cnt = 0;
        }
 for(int i = 0 ; i < n ; i++){
    if(nums[i] == i) {
        return nums[i];
        break;
 }
 }
 return -1;
    }
};