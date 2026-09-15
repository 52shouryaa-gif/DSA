class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int i = 0;
        int n = nums.size();
        int j = n-1;
        // 0 1 3 4 4 5
        map<float , int>mpp;
        while(i<j){
            mpp[float(float((nums[i]+nums[j]))/2)]++;
            i++;
            j--;
        }
        return mpp.size();
    }
};