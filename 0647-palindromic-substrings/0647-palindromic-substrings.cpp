class Solution {
public:
    bool ispal(int i, int j, string &s,int n,vector<vector<int>>&dp){
        if(i>=j)return true;
        
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j] && ispal(i+1,j-1,s,n,dp)){
            return dp[i][j]=true;
        }
        return dp[i][j]=false;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1)); 

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(ispal(i,j,s,n,dp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};