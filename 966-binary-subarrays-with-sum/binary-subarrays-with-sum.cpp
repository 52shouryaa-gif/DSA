class Solution {
public:
int sum(vector<int>& nums, int goal){
    
 int l = 0;
   if(goal<0) return 0;
        int r = 0;
        int n = nums.size();
        int cnt = 0;
        int maxi = 0;
       
        while(r<n){
           
            maxi += nums[r];
            while(maxi >goal){
               maxi = maxi - nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        

        return cnt;
    }    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a = sum(nums , goal);
        int b = sum(nums , goal-1 );
        return a-b;
    }
};