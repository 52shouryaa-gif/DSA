#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Distance matrix initialized with -1 (or we can use 'mat' itself)
        vector<vector<int>> dis(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Step 1: Push all 0s into the queue as starting points
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int der[] = {-1, 1, 0, 0};
        int dec[] = {0, 0, -1, 1};

        // Step 2: Perform BFS
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            
            dis[r][c] = step;

            for(int i = 0; i < 4; i++){
                int delr = r + der[i];
                int delc = c + dec[i];

                // Check bounds and whether the cell has been visited
                if(delr >= 0 && delc >= 0 && delr < n && delc < m && vis[delr][delc] == 0){
                    vis[delr][delc] = 1;
                    q.push({{delr, delc}, step + 1});
                }
            }
        }

        return dis;
    }
};