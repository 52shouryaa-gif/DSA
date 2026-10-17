class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                df(adj, vis, i);
            }
        }

        return cnt;
    }

    void df(vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                df(adj, vis, it);
            }
        }
    }
};