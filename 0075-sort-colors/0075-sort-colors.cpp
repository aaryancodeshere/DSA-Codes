class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int j=0,k=n-1,i=0;
        while(i<=k){
            if(nums[i]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[k]);
                k--;
            }
            else{
                i++;
            }
        }
    }
};