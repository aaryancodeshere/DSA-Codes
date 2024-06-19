class Solution {
public:
    int dp[301][301];

    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi){
        if(i>=matrix.size() || j>=matrix[0].size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int right = solve(matrix,i,j+1,maxi);
        int down = solve(matrix,i+1,j,maxi);
        int dia = solve(matrix,i+1,j+1,maxi);
        
        if(matrix[i][j]=='1'){
           int ans = 1+ min(right,min(down,dia));
            maxi=max(ans,maxi);
            return dp[i][j]=ans ;
        }
        else{
             return 0;
        }
                
    }

    int maximalSquare(vector<vector<char>>& matrix) {
      int maxi=0;
      memset(dp,-1,sizeof(dp));
      solve(matrix,0,0,maxi);
      return maxi*maxi;
    }
    };