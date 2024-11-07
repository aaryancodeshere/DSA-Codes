class Solution {
public:
   vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,0,1});

        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int time = top[0],row=top[1],col = top[2],step=top[3];
            for(auto dir:directions){
                int nextrow= row+dir[0];
                int nextcol = col + dir[1];
                int toadd=2;
                int nextadd=1;
                if(step%2){
                    toadd=1;
                    nextadd=2;
                }

                if(nextrow>=0 && nextrow<n && nextcol>=0 && nextcol<m){
                    int newtime = toadd+max(time,moveTime[nextrow][nextcol]);
                    if(newtime<ans[nextrow][nextcol]){
                        ans[nextrow][nextcol]=newtime;
                        pq.push({newtime,nextrow,nextcol,nextadd});
                    }
                }
                
            }
            
        }
        return ans[n-1][m-1];

    }
};