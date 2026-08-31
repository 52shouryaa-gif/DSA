class Solution {
public:
int findays(vector<int>& nums , int mid){
    int load = 0;
    int cnt = 1;
    for(int i = 0 ; i < nums.size() ; i++){
        if(load + nums[i] > mid){
            load = nums[i];
            cnt++;
        }

        else load += nums[i];
    }
    return cnt;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin() , weights.end());
        int right = accumulate(weights.begin() , weights.end(),0);
        while(left  <= right){
            int mid = (left + right)/2;
            int tar = findays(weights , mid);
            if(tar<=days) right = mid -1;
            else left = mid + 1;
        }
        return left;
    }
};