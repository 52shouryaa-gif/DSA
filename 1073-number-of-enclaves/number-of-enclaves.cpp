class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>>q;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1&&(i == 0 || j == 0 || i==n-1 || j == m-1 )){
                   vis[i][j] = 1;
                   q.push({i , j});
                }
            }
        }
        int delr[] = {-1 , 1 , 0 , 0};
        int delc[] = {0 , 0 , -1 , 1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = delr[i] + row;
                int ncol = delc[i] + col;
                if(nrow >=0 && ncol >= 0 && nrow <n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1  ){
                    vis[nrow][ncol] = 1;
                    q.push({nrow , ncol});
                }
            }


        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1 ){
                cnt++;
            }}
        }
        return cnt;
    }
};