class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnt = 0 ;
        int mini = *min_element(nums1.begin() , nums1.end());
        if(nums1.size()==1) return true ;
        if(mini%2==1) return true;
        else{
         for(auto it:nums1){
           if(it%2==0){
            cnt++;
           }
           
         }
         if(nums1.size()!=cnt) return false;
        }
        
        return true;
    }
};