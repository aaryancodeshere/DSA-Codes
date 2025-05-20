class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int j,k;
        int ans = 100000;
        
        for(int i=0; i<n-2; i++){
            int curr = nums[i];
            j=i+1,k=n-1;

            while(j<k){
                int temp = curr+nums[j]+nums[k];
                if(target==temp)return target;

                else if(abs(target-temp)<abs(target-ans)){
                    ans = temp;
                }
                if(temp<target){
                    j++;
                }
                else{
                    k--;
                }
                
            }
        }

        return ans;

    }
};