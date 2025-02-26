class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = nums[0];
        int curr1 = nums[0];
        int n = nums.size();
        for(int i =1; i<n; i++){
            curr1 = max(nums[i],curr1+nums[i]);
            ans1 = max(ans1,curr1);
            
        }

        int ans2 = nums[0];
        int curr2 = nums[0];
    
        for(int i =1; i<n; i++){
            curr2 = min(nums[i],curr2+nums[i]);
            ans2 = min(ans2,curr2);
            
        }

        int ans = max(ans1,abs(ans2));
        return ans;

    }
};