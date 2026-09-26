class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int , int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        vector<int>n;
        for(auto it: mpp){
            if(it.second == 1) n.push_back(it.first);
        }
        return n;
    }
};