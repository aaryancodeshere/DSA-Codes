class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0, j=n-1;
        int ans = -1;

        while(i<=j){
            int mid = i + (j-i)/2;

            if(nums[mid]==target)return mid;
            if(nums[mid]>target){
                j = mid-1;
                ans = mid;
            }
            else{
                i = mid+1;
                ans = mid +1;
            }
        }
        return ans;
    }
};