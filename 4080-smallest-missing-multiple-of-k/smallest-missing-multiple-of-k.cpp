class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
         unordered_map<int , int>mpp;
         int cnt = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]++];
        }
        while(true){
        if(mpp.find(k*cnt)!=mpp.end()){
         cnt++;
        }
        else{
         
         return cnt*k;
        }
        }
        return 0;
    }
};