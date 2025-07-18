class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans(k,vector<int>(n,1));
        int maxi = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int mod = (nums[i]+nums[j])%k;
                ans[mod][i] = max(ans[mod][i],1+ans[mod][j]);

                maxi = max(maxi, ans[mod][i]);
            }
        }

        return maxi;
    }
};