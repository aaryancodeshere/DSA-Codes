class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,curr=0;
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==1){
                curr++;
                maxi = max(maxi,curr);
            }
            else{
                curr=0;
            }
            i++;
        }

        return maxi;
    }
};