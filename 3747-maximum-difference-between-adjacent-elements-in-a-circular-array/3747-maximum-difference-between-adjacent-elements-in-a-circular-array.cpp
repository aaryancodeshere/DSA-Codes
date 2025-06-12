class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=1; i<=n; i++){
            int curr = abs(nums[i%n]-nums[i-1]);
             ans = max(ans,curr);
        }

        return ans;
    }
};