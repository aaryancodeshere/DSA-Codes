class Solution {
public:
    int bs(vector<int>& nums,int sum, int l , int r){
        int idx = r+1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(nums[mid]>=sum){
                idx = mid;
                r = mid-1;
            }
            else if(nums[mid]<sum){
                l = mid+1;
            }
        }
        return idx;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n ;j++){
                int sum = nums[i]+nums[j];
                int idx = bs(nums,sum,j+1,n-1);
                ans+=(idx-j-1);
            }
        }

        return ans;
    }
};