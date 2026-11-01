class Solution {
    private:
    void dfs(vector<vector<char>>& board , int i , int j , int delr[] , int delc[] , vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();
        vis[i][j] = 1;

        for(int k = 0 ; k < 4 ; k++){
            int nrow = i + delr[k];
            int ncol = j + delc[k];
            if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(board , nrow , ncol , delr , delc , vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int delr[] = {-1 , 1 , 0 , 0};
        int delc[] = {0 , 0 , -1 , 1};
        for(int i = 0 ; i < m  ; i++){
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(board , 0 , i , delr , delc , vis);
            }
            if(board[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(board , n-1 , i , delr , delc , vis);
            }
        }
        for(int i = 0 ; i < n  ; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(board , i , 0 , delr , delc , vis);
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(board , i , m-1 , delr , delc , vis);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
