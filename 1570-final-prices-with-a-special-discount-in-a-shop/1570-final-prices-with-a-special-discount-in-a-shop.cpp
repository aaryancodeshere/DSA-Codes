class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>> s;
        int n = prices.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top().first>prices[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=prices[i];
            }
            else{
                int idx = s.top().second;
                int price = prices[i]-prices[idx];
                ans[i]=price;
            }
            s.push({prices[i],i});

        }
        return ans;
    }
};