class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int zerocount = 0;
        int ans = 0;
        while(j<n){
            if(nums[j]==0){
                zerocount++;
            }
            while(i<=j && zerocount>k){
                
                zerocount -= nums[i]==0;
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};