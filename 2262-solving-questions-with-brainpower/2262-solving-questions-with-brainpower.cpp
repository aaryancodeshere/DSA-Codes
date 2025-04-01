class Solution {
public:

    int n;
    
    long long solve(vector<vector<int>>& questions, int i,vector<long long>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];

        long point = questions[i][0];
        long toskip = questions[i][1];

        long long take = point + solve(questions, i + toskip +1,dp);
        long long nottake = solve(questions, i+1,dp);

        return dp[i]=max(take,nottake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long> dp(n+1,-1);
        long long ans = solve(questions, 0,dp);

        return ans;
    }
};