class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> fmin(n,nums[0]);
        vector<int> fmax(n,nums[0]);
        vector<int> bmax(n,nums[n-1]);
        vector<int> bmin(n,nums[n-1]);
        

        for(int i = 1;i<n; i++){
            fmin[i] = min(fmin[i-1],nums[i]);
            fmax[i] = max(fmax[i-1],nums[i]);
            bmin[n-i-1] = min(bmin[n-i],nums[n-i-1]);
            bmax[n-i-1] = max(bmax[n-i],nums[n-i-1]);

        }
        int ans= INT_MAX;
        for(int i = 0; i<n-1; i++){
            int ans1 = abs(fmax[i] - bmin[i+1]);
            int ans2 = abs(fmin[i] - bmax[i+1]);
            ans = min(ans,min(ans1,ans2));
        }
        return ans;

    }
};