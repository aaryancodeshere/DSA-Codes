class Solution {
public:

    void dfs(int i,unordered_map<int,vector<int>>& adj,int n,vector<bool>& visited){
        visited[i]=true;
        for(auto &ngbr: adj[i]){
            if(!visited[ngbr]){
                dfs(ngbr,adj,n,visited);
            }
            
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int , vector<int>> adj;
        int n = isConnected.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)continue;

                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i,adj,n,visited);
            }
        }
        return ans;
    }
};