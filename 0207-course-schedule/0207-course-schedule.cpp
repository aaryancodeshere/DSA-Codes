class Solution {
public:
    int n;
    bool dfs(unordered_map<int,vector<int>>& adj, int curr,vector<bool>& visited, vector<bool>& currrec){
        visited[curr] = true;
        currrec[curr] = true;
        
        for(auto &ngbr: adj[curr]){
            if(!visited[ngbr] && dfs(adj,ngbr,visited,currrec)){
                return true;
            }
            else if(currrec[ngbr]){
                return true;
            }
        }

        currrec[curr] = false;
        return false;
        
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto &pre: prerequisites){
            int u = pre[1];
            int v = pre[0];
            adj[v].push_back(u);
        }
        bool ans = true;
        n = numCourses;
        vector<bool> visited(n,false);
        vector<bool> currrec(n,false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(adj, i, visited, currrec)) {
                return false;
            }
        }
        return true;

    }
};