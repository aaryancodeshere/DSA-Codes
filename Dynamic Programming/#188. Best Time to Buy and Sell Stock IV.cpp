class Solution {
public:
    int dp[102][102][1001][2];
    int solve(vector<int>& prices, int buy, int sell, int index,int buys){
        if(index==prices.size())return 0;
        if(!buy && !sell)return 0;
        if(dp[buy][sell][index][buys] != -1){
            return dp[buy][sell][index][buys];
        }
        int profit =0;
        if(buys){
            int buykro=-prices[index]+solve(prices,buy-1,sell,index+1,0);
            int skipkro= solve(prices,buy,sell,index+1,buys);
            profit= max(buykro,skipkro);
        }
        else{
            int sellkro=+prices[index]+solve(prices,buy,sell-1,index+1,1);
            int skipkro=solve(prices,buy,sell,index+1,buys);
            profit = max(sellkro,skipkro);
        }
        return dp[buy][sell][index][buys]=profit;


    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices, k,k,0,1);
    }
};