class Solution {
public:
    void bfs(vector<int>& edges, int node, vector<int>& d, int n){
        queue<int> que;
        que.push(node);
        vector<bool> visited(n,false);
        visited[node] = true;
        int dist = 0;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            d[u] = dist;

            int next = edges[u];
            if(next!=-1 && !visited[next]){
                que.push(next);
                visited[next] = true;
                dist++;
            }

        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> d1(n,INT_MAX);
        vector<int> d2(n,INT_MAX);

        d1[node1] = 0;
        d2[node2] = 0;
        bfs(edges,node1,d1,n);
        bfs(edges,node2,d2,n);
        
        int mini = INT_MAX;
        int idx = -1;

        for(int i=0; i<n; i++){
            int curr = max(d1[i],d2[i]);
            if(curr<mini){
                idx = i;
                mini = curr;
            }
        }
        return idx;
    }
};