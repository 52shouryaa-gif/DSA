class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       vector<int> flat;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                flat.push_back(matrix[i][j]);
            }
        }
        
        
        sort(flat.begin(), flat.end());
        
        
        return flat[k - 1];
    }
};