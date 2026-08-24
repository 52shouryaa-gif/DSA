class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int , int> arr;
        vector<int> tmpl;
        int mini = ((int)(nums.size()/3) + 1);
        for(int i = 0; i<nums.size(); i++){
            arr[nums[i]]++;
             if(arr[nums[i]] == mini){
                tmpl.push_back(nums[i]);
             }
        }
       sort(tmpl.begin() , tmpl.end());
       return tmpl;
    }
};