class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int maxi=1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    ans[i] = max(ans[i],1+ans[j]);
                    maxi = max(maxi,ans[i]);
                }
            }
        }

        return maxi;
    }
};