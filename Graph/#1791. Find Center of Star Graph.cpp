class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        int n= edges.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                m[edges[i][j]]++;
            }
        }
        for(auto i:m){
            if(i.second==n){
                return i.first;
            }
        }
        return -1;
    }
};