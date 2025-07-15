class Solution {
public:
    int nextGreaterElement(int k) {
        int temp = k;
        vector<int> nums;

        while(k){
            nums.push_back(k%10);
            k=k/10;
        }

        reverse(nums.begin(),nums.end());

        int idx = -1;
        int n = nums.size();

        for(int i = n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                idx = i-1;
                break;
            }
        }

        int swapidx=idx;
        if(idx == -1)return -1;
        if(idx!=-1){

            for(int j = n-1; j>= idx+1; j--){
                if(nums[j]>nums[idx]){
                    swapidx=j;
                    break;
                }
            }
            swap(nums[idx],nums[swapidx]);
        }  

        reverse(nums.begin() + idx+1,nums.end());
        long long ans=0;

       for (int i = 0; i < n; i++) { 
            ans = ans * 10 + nums[i];
        }

        if(ans > INT_MAX || ans <= temp) return -1;

        return ans;
    }
};