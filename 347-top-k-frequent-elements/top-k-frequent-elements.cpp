class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int , int> mpp;
       for(auto it: nums){
        mpp[it]++;
       }
      vector<pair<int , int>> arr;
      for(auto it : mpp){
        arr.push_back({it.second , it.first});
      }
      sort(arr.rbegin() , arr.rend());
      vector<int>ar;
      for(int  i = 0 ; i < k ; i++){
        ar.push_back(arr[i].second);
      }
      return ar;
    }
};