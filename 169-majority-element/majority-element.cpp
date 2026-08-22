class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(auto num:nums){
            if(num == el){
                cnt++;
            }
            else if (cnt == 0){
                el = num;
                cnt = 1;
            }
            else cnt--;
        }
        return el;
    }
};