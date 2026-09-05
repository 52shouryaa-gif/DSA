class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int al = 0;
        int bl = 0;
        for(int it:aliceSizes) al+= it;
        for(int it:bobSizes) bl+= it;
        
        int diff = (bl - al)/2;
        
        unordered_set<int> mpp(bobSizes.begin() , bobSizes.end());
        for(auto it :aliceSizes){
          if(mpp.count(it + diff)){
            return {it , it+diff};
          }
        }
        return {};
    }
};