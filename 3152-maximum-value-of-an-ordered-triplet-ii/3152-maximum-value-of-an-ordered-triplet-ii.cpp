class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> currmax(n);
        vector<int> prevmax(n);
        currmax[n-1] = nums[n-1];
        prevmax[0] = nums[0];
        for(int i=n-2; i>=0; i--){
            currmax[i] = max(currmax[i+1],nums[i]);
        }
        for(int i=1; i<n; i++){
            prevmax[i]= max(prevmax[i-1],nums[i]);
        }

        long long ans = 0;

        for(int i=1; i<n-1; i++){
            long long curr = (long long)(prevmax[i-1]-nums[i])*currmax[i+1];
            ans = max(ans,curr);
        }

        return ans;

    }
};