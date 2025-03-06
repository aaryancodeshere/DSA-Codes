class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n = grid.size();
        vector<int> ans(2,0);
        int a,b;
        int sum =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mp[grid[i][j]]){
                    a=grid[i][j];     
                }
                mp[grid[i][j]]++;
                sum+=grid[i][j];
            }
        }
        b = abs(sum - (n*n*(n*n+1)/2)-a);
        ans[0]=a;
        ans[1]=b;
        cout<<a<<" "<<b;
        return ans;
    }
};