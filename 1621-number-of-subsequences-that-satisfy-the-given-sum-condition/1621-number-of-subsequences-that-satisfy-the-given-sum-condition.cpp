class Solution {
public:
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0,j=n-1;

        vector<int> power(n);
        power[0] = 1;
        
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        } 

        sort(nums.begin(),nums.end());

        int ans=0;

        while(i<=j){
            int sum = nums[i]+nums[j];

            if(sum<=target){
                int diff = j-i;
                ans = (ans % M + power[diff]) % M;
                i++;

            }
            else if(sum>target){
                j--;
            }
    
        }

        return ans;
    }
};