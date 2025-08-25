class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocount = 0;

        int i=0,j=0;
        int n = nums.size();
        int ans = 0;

        while(j<n){
            
            
            if(nums[j]==0){
                zerocount++;
                j++;
            }
            else{
                j++;
            }
            

            while(i<n && zerocount>1){
                zerocount -= (nums[i]==0);
                i++;
            }

            ans = max(ans,j-i-1);
            
        }


        return ans;
    }
};