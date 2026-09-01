class Solution {
public:
bool func(vector<int>& matri , int tar){
    int left = 0;
    int right = matri.size() - 1;
    while(left <= right){
        int mid = (left + right)/2;
    if(tar == matri[mid]){
        return true;
    }
    else if(tar>matri[mid]) left = mid + 1;
    else right = mid - 1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0 ; i < matrix.size();i++){
            
            if(func(matrix[i] , target)) return true ;
        }
        return false;
    }
};