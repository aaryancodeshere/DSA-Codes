class Solution {
public:

    bool isvalid(vector<int>& nums, int mid, int p){
        int count = 0;

        int n = nums.size();
        int i = 0;
        while(i<n-1){
            if(nums[i+1]-nums[i] <= mid){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int ans ;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums[n-1]-nums[0];

        while(l<=r){
            int mid = l + (r-l)/2;

            if(isvalid(nums,mid,p)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};