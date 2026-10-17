class Solution {
private:
    void bf(vector<vector<char>>& grid, vector<vector<int>>& vis, int row,
            int col) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = -1 ; i <= 1 ; i++){
                for(int j = -1 ; j <= 1 ; j++){
                   int del = r + i;
                   int delc = c + j;if (abs(i) + abs(j) != 1) continue;
                   if(del<n && del>=0 &&  delc < m && delc >=0 && !vis[del][delc] && grid[del][delc] == '1' ){
                    
                    q.push({del , delc});
                    vis[del][delc] = 1;
                   }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bf(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};