class Solution {
private:
   bool dfs(vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj, int i) {
     vis[i] = 1;
     pathvis[i] = 1;
     for(auto it : adj[i]){
       if(!vis[it]){
           if(dfs(vis, pathvis, adj, it) == true) return true;
       }
       else if(pathvis[it]) return true;
     }
     pathvis[i] = 0;
     return false;
   }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(vis, pathvis, adj, i)) return false;
            }
        }
        return true;
    }
};