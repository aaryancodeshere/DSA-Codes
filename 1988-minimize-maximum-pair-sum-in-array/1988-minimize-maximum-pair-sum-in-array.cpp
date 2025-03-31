class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n/2; i++){
            ans = max((nums[i]+nums[n-i-1]),ans);
        }
        return ans;
    }
};