class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count1=0,count2=0,i=0,j=1,ans=0;
        while(j<nums.size()){
            if(nums[j]>nums[j-1]){
                count1++;
                ans=max(ans,count1);
                j++;
            }
            else{
                j++;
                count1=0;
            }
        }
        j=1;

         while(j<nums.size()){
            if(nums[j]<nums[j-1]){
                count2++;
                ans=max(ans,count2);
                j++;
            }
            else{
                j++;
                count2=0;
            }
        }
        return ans+1;

    }
};