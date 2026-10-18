class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>> q;
        int cntfr = 0;
        for(int i = 0 ; i < n ; i++){
           for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 2) q.push({i , j});
            else if(grid[i][j] == 1) cntfr++;
           }
        }
        int min = 0;
        vector<vector<int>> ans = grid;
        int delr[] = {-1 , 1 , 0 , 0};
        int delc[] = {0 , 0 , -1 , 1};
        while(!q.empty() && cntfr > 0){
            int l = q.size();
            for(int i = 0 ; i < l ; i++){
          auto[row , col] = q.front();
          q.pop();
          for(int i = 0 ; i < 4;i++){
            int r = row + delr[i];
            int c = col + delc[i];
            if(r>=0 && r<n && c >=0 && c<m && grid[r][c]==1 && ans[r][c]!=2){
                ans[r][c] = 2;
                cntfr--;
                q.push({r , c});
            }
          }}
          min++;
        }
        if(cntfr>0) return -1;
        return min;
    }
};