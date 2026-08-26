class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int , int> arr;
        vector<int> tmpl;
        int n = nums.size();
      int mini = (int)(n/3)+1;
     for(auto it:nums) arr[it]++;
     for(auto it:arr){
        if(it.second>=mini) tmpl.push_back(it.first);
     }
     sort(tmpl.begin() , tmpl.end());
      return tmpl;
    }
};