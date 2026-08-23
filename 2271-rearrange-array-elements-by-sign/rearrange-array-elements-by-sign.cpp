class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a(nums.size() , 0);
        int pos = 0;
        int neg = 1;
        for(int i = 0;i<nums.size(); i++){
            if(nums[i]<0){
                a[neg]=nums[i];
                neg+=2;
            }
            else{
                a[pos] = nums[i];
                pos+=2;
            }
        }
        return a;
    }
};