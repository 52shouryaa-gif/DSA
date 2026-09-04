class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> arr(nums1.begin() , nums1.end());
        vector<int>temp;
    
        for( auto it:nums2){
            if(arr.find(it) != arr.end()){
                temp.push_back(it);
                arr.erase(it);
            }
        }
        return temp;
    }
};