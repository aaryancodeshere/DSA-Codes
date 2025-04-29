class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        long long ans = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        int count = 0;

        while (j < nums.size()) {
            if(nums[j]==max)count++;

            while (count >=k && i <= j) {
                ans += nums.size() - j;
                if(nums[i]==max)count--;
                
                i++;
            }
            j++;
        }
        return ans;
    
}
}
;