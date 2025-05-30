class Solution {
public:
    void check(unordered_map<int,vector<int>>& adj, vector<int>& indegree, int n,vector<int>& ans){
        queue<int> q;
        int count=0;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            count++;
            for(auto &ngbr : adj[u]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        if(count!=n)ans= {};

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto &pre: prerequisites){
            int u = pre[1];
            int v = pre[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans;

        check(adj,indegree,numCourses,ans);
        return ans;

    }
};