class Solution {
public:
    int n;

    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (i >= n)
            return false;
        if (target == 0)
            return true;
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool take = false;
        if (target - nums[i] >= 0)
            take = solve(nums, i + 1, target - nums[i], dp);
        bool nottake = solve(nums, i + 1, target, dp);

        return dp[i][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(nums, 0, target, dp);
    }
};